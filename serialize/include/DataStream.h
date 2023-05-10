/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-25 15:16:08
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-05-10 11:28:05
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
#include <algorithm>

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
                using type = T;
            };
            
            // deque类型
            template<typename T,typename... Types>
            struct IsContainerType<std::deque<T, Types...>>
            {
                static const bool value = true;
                using type = T;
            };
 
            // set类型
            template<typename T,typename... Types>
            struct IsContainerType<std::set<T, Types...>>
            {
                static const bool value = true;
                using type = T;
            };
            
            template<typename T,typename... Types>
            struct IsContainerType<std::list<T, Types...>>
            {
                static const bool value = true;
                using type = T;
            };
            
        // 定义获取容器类型的模板
        template<typename T,typename... Types>
        constexpr bool is_container = IsContainerType<T, Types...>::value;
        template<typename T,typename... Types>
        using CintainerType = typename IsContainerType<T, Types...>::type;     

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
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = (char *)&value;
                    char * end = (char *)&value + sizeof(T);
                    std::reverse(frist, end);
                }
                write_data((char *)&value, sizeof(value));
            }

      
            template<typename T, typename std::enable_if<is_container<T>, int>::type = 0>
            void write(const T & value)
            {
                char type = static_cast<char>(DataType::CONTAINER);
                write_data((char *)&type, sizeof(char));
                int32_t len = value.size();
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = (char *)&len;
                    char * end = (char *)&len + sizeof(len);
                    std::reverse(frist, end);
                }
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
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = (char *)&len;
                    char * end = (char *)&len + sizeof(len);
                    std::reverse(frist, end);
                }
                write_data((char *)&len, sizeof(int32_t));
                
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = (char *)value.data();
                    char * end = (char *)value.data() + len;
                    std::reverse(frist, end);
                }
                write_data(value.data(), len);
            }

            // template<typename T, typename S>
            // void write(const std::map<T, S> & value)
            // {
                
            // }
            template<typename T, typename std::enable_if<!is_container<T>, int>::type = 0>
            bool read(T& value)
            {
                char* type = static_cast<char *>(&m_buf[m_pos]);
                DataType rType = declDataType(value);
                if (*type != rType)
                {
                    return false;
                }
                m_pos++;
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = &m_buf[m_pos];
                    char * end = &m_buf[m_pos] + sizeof(T);
                    std::reverse(frist, end);
                }
                std::memcpy(&value, &m_buf[m_pos], sizeof(value));
                m_pos += sizeof(value);
                return true;
            }
            template<typename S = void>
            bool read(std::string & value)
            {
                char* type = static_cast<char *>(&m_buf[m_pos]);
                if (*type != DataType::STRING)
                {
                   return false;
                }
                m_pos++;
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = &m_buf[m_pos];
                    char * end = &m_buf[m_pos] + sizeof(int32_t);
                    std::reverse(frist, end);
                }
                int32_t* len = (int32_t *)(&m_buf[m_pos]);
                m_pos += 4;
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = &m_buf[m_pos];
                    char * end = &m_buf[m_pos] + *len;
                    std::reverse(frist, end);
                }
                value = std::string(&m_buf[m_pos], *len);
                m_pos += *len;
                return true;
            }
            
            template<typename T, typename std::enable_if<is_container<T>, int>::type = 0>
            bool read(T& value)
            {
                char* type = static_cast<char *>(&m_buf[m_pos]);
                if (*type != DataType::CONTAINER)
                {
                   return false;
                }
                m_pos++;
                if (m_endian == Endian::BigEndian)
                {
                    char * frist = &m_buf[m_pos];
                    char * end = &m_buf[m_pos] + sizeof(int32_t);
                    std::reverse(frist, end);
                }
                int32_t* len = (int32_t *)&m_buf[m_pos];
                m_pos += 4;
                
                for (size_t i = 0; i < *len; i++)
                {
                    CintainerType<T> data;
                    bool isRead = read(data);
                    if (!isRead)
                    {
                       
                        return false;
                    }
                    value.push_back(data);
                }
                return true;
            }
            
            template<typename T>
            DataStream& operator<<(T& value)
            {
                write(value);
                return *this;
            }

            template<typename T>
            DataStream& operator>>(T& val)
            {
                read(val);
                return *this;
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