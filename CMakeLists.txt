cmake_minimum_required(VERSION 3.0)
project(ros_test)

# 如果代码需要支持C++11，就直接加上这句
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
add_definitions("-Wall -g")
#添加OpenCV库，头文件
# find_package(OpenCV REQUIRED)
# include_directories(${OPENCV_INCLUDE_DIRS})


include_directories(${PROJECT_SOURCE_DIR}/serialize/include)

add_executable(ros_test src/main.cpp serialize/src/DataStream.cpp)

#链接库文件到工程
target_link_libraries(ros_test)