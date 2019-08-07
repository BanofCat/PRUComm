#ifndef __MODULES_PARSER_RW_BUF_BASE_H__
#define __MODULES_PARSER_RW_BUF_BASE_H__

class RWBufBase
{

public:
    virtual int updateData(const unsigned char* data, unsigned int data_size_byte) = 0;
    virtual const unsigned char* get_data_ptr() = 0;
    virtual unsigned int get_data_length() = 0;
}


#endif // !__MODULES_PARSER_RW_BUF_BASE_H__