/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-25 15:16:08
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-05-06 17:13:17
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

namespace w{
    namespace serialize{
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
                VECTOR,
                SET,
                MAP,
                LIST,
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
            template<typename T>
            void write(const T & value)
            {
                char type = static_cast<char>(declDataType(value));
                write_data((char *)&type, sizeof(char));
                if (type == (char)DataType::STRING)
                {
                    int32_t len = value.size();
                    write_data((char *)&len, sizeof(int32_t));
                    write_data(value.data(), len);
                    return;
                }
                write_data((char *)&value, sizeof(value));
            }
            template<typename T>
            void write(const std::vector<T> & value)
            {
                char type = static_cast<char>(DataType::VECTOR);
                write_data((char *)&type, sizeof(char));
                write_data((char *)&value, sizeof(value));
            }
            
        private:
            std::vector<char> m_buf;
            // template<typename T>
            // DataType declSTL(std::)
            // {

            // }
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
                if (std::is_same<std::string, Type>())
                    return DataType::STRING;
                std::logic_error("error type to write");
            }
            Endian m_endian;
            int m_pos;
        };
        
       
        
    }
}