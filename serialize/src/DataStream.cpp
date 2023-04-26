/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-04-26 11:03:45
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-04-26 17:11:16
 * @FilePath: /ros/serialize/src/DataStream.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "DataStream.h"

namespace w{
    namespace serialize{
        DataStream::DataStream() : m_endian(declEndian())
        {
        }
        
        DataStream::~DataStream()
        {
        }

        void DataStream::show()
        {
            
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
                    cap *= cap;
                }
            }
            m_buf.reserve(cap);
        }

        void write_data(const char * data, int32_t len)
        {

        }

        void DataStream::write(const char & value)
        {

        }

        void DataStream::write(const bool & value)
        {
            
            char type = static_cast<char>(DataType::BOOL);
            write_data((char *)&type, sizeof(DataType::BOOL));
            write_data((char *)&value, sizeof(value));
        }

    }
}