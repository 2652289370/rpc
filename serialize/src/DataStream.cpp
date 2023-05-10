/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-26 11:03:45
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-05-10 11:09:13
 * @FilePath: /ros/serialize/src/DataStream.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "DataStream.h"

namespace w{
    namespace serialize{
        DataStream::DataStream() : m_endian(declEndian()) , m_pos(0)
        {
        }
        
        DataStream::~DataStream()
        {
    
        }

        void DataStream::show()
        {
            char type = *((char *)&m_buf[m_pos]);
            m_pos++;
            switch (type)
            {
            case DataType::CHAR:
            {
                char s = *((char *)&m_buf[m_pos]);
                m_pos++;
                std::cout << s << std::endl;
                break;
            }
            case DataType::BOOL:
            {
                if ((int)(m_buf[m_pos]) == 1)
                {
                    std::cout << "true" << std::endl;
                }
                else
                {
                    std::cout << "false" << std::endl;
                }
                m_pos++;
                break;
            }      
            case DataType::STRING:
            {
                int32_t len = (int32_t)(m_buf[m_pos]);
                m_pos += 4; 
                std::string st = std::string(&m_buf[m_pos], len);
                std::cout << st << std::endl;
                break;
            }
            case DataType::DOUBLE:
            {
                double a = *(double *)&m_buf[m_pos];
                std::cout << a << std::endl;
                break;
            }
            case DataType::CONTAINER:
            {
                int32_t len = (int32_t)(m_buf[m_pos]);
                m_pos += 4;
                for (size_t i = 0; i < len; i++)
                {
                    m_pos++;
                    double a = *(double *)&m_buf[m_pos];
                    m_pos += 8;
                    std::cout << a << std::endl;
                }
                break;
            }
                
            default:
                std::logic_error("error type");
                break;
            }
            
        }

        void DataStream::reserve(int32_t len)
        {
            size_t size = m_buf.size();
            size_t cap = m_buf.capacity();
            while (size + len > cap)
            {
                if (cap == 0)
                {
                    cap = 1;
                }
                else
                {
                    cap *= 2;
                }
            }
            m_buf.reserve(cap);
        }

        void DataStream::write_data(const char * data, int32_t len)
        {
            reserve(len);
            size_t size = m_buf.size();
            m_buf.resize(size + len);
            std::memcpy(&m_buf[size], data, len);
        }

        // template<typename T>
        // void DataStream::write(const T & value)
        
    }
}