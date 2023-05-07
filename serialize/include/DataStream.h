/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-25 15:16:08
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-05-07 16:55:13
 * @FilePath: /ros/serialize/include/DataStream.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <iostream>
#include <string.h>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <map>

namespace w{
    namespace serialize{

        template<typename T,typename... Types>
            struct IsContainerType
            {
                static const bool value = false;
            };
            
            // Vector类型为true
            template<typename T,typename... Types>
            struct IsContainerType<std::vector<T, Types...>>
            {
                static const bool value = true;
            };
            
            // deque类型
            template<typename T,typename... Types>
            struct IsContainerType<std::deque<T, Types...>>
            {
                static const bool value = true;
            };
 
            // set类型
            template<typename T,typename... Types>
            struct IsContainerType<std::set<T, Types...>>
            {
                static const bool value = true;
            };
            
            template<typename T,typename... Types>
            struct IsContainerType<std::list<T, Types...>>
            {
                static const bool value = true;
            };
            
        // 定义获取容器类型的模板
        template<typename T,typename... Types>
        constexpr bool is_container = IsContainerType<T, Types...>::value;
                

        class DataStream
        {
        public:
            enum DataType{
                BOOL = 0,
                CHAR,
                INT32,
                INT64,
                FLOAT,
                DOUBLE,
                STRING,
                CONTAINER,
                MAP,
                CUSTOM
            };
            enum Endian{
                BigEndian = 0,
                SmallEndian
            };
        private:
            Endian declEndian()
            {
                int _n = 0x12345678;
                if(*(char *)&_n == 0x12 )
                    return Endian::BigEndian; 
                return Endian::SmallEndian;
            }
            void reserve(int32_t len);
        public:
            DataStream(/* args */);
            ~DataStream();

            void show();

            void write_data(const char * data, int32_t len);


            template<typename T, typename std::enable_if<!is_container<T>, int>::type = 0>
            void write(const T & value)
            {
                char type = static_cast<char>(declDataType(value));
                write_data((char *)&type, sizeof(char));
                write_data((char *)&value, sizeof(value));
            }

      
            template<typename T, typename std::enable_if<is_container<T>, int>::type = 0>
            void write(const T & value)
            {
                char type = static_cast<char>(DataType::CONTAINER);
                write_data((char *)&type, sizeof(char));
                int32_t len = value.size();
                write_data((char *)&len, sizeof(len));
                for (auto it = value.begin(); it != value.end(); it++)
                {
                    write(*it);
                }
            }
            template<typename S = void>
            void write(const std::string & value)
            {
                char type = static_cast<char>(DataType::STRING);
                write_data((char *)&type, sizeof(char));
                int32_t len = value.size();
                write_data((char *)&len, sizeof(int32_t));
                write_data(value.data(), len);
            }

            template<typename T, typename S>
            void write(const std::map<T, S> & value)
            {
                
            }
            template<typename T>
            bool read(T& value)
            {
                
            }
            
        private:
            std::vector<char> m_buf;

            
            template<typename Type>
            DataType declDataType(const Type & t)
            {
                if (std::is_same<bool, Type>())
                    return DataType::BOOL;
                if (std::is_same<char, Type>())
                    return DataType::CHAR;
                if (std::is_same<int32_t, Type>())
                    return DataType::INT32;
                if (std::is_same<int64_t, Type>())
                    return DataType::INT64;
                if (std::is_same<float, Type>())
                    return DataType::FLOAT;
                if (std::is_same<double, Type>())
                    return DataType::DOUBLE;
                std::logic_error("error type to write");
            }
            Endian m_endian;
            int m_pos;
        };
        
       
        
    }
}