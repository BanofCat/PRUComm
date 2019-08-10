#ifndef __MODULES_PARSER_RW_BUF_BASE_H__
#define __MODULES_PARSER_RW_BUF_BASE_H__
#include "error_code.h"
#include "string.h"

class RWBufBase
{
protected:
    unsigned char* data;
    unsigned int data_length;

public:
    virtual int updateData(const unsigned char* data, unsigned int data_size_byte)
    {
        if (data_size_byte > this->data_length || data == NULL) {
            return ARGS_INVALID;
        }
        memcpy(this->data, data, data_size_byte);
        return OK;
    }

    virtual const unsigned char* getDataPtr()
    {
        return this->data;
    }

    virtual unsigned int getDataLength()
    {
        return this->data_length;
    }

};  // !class RWBufBase


#endif // !__MODULES_PARSER_RW_BUF_BASE_H__