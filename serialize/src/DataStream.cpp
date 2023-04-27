/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-26 11:03:45
 * @LastEditors: w 2652289370@qq.com
 * @LastEditTime: 2023-04-27 16:33:01
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
            case DataType::BOOL:
                if ((int)(m_buf[m_pos]) == 1)
                {
                    std::cout << "true" << std::endl;
                }
                else
                {
                    std::cout << m_buf.size() << std::endl;
                    for (size_t i = 0; i < m_buf.size(); i++)
                    {
                        std::cout << m_buf[i] << std::endl;
                    }
                    
                }
                m_pos++;
                break;
            
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

        void DataStream::write(const char & value)
        {

        }

        void DataStream::write(const bool & value)
        {
            char type = static_cast<char>(DataType::BOOL);
            std::cout << sizeof(DataType::BOOL) << std::endl;
            write_data((char *)&type, sizeof(char));
            write_data((char *)&value, sizeof(value));
        }

    }
}