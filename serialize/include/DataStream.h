/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-25 15:16:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-04-26 17:01:27
 * @FilePath: /ros/serialize/include/DataStream.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <iostream>
#include <string.h>
#include <cstdint>
#include <cstring>
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
                LIST
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
            void write(const char & value);
            void write(const bool & value);

        private:
            std::vector<char> m_buf;
            Endian m_endian;
        };
        
       
        
    }
}