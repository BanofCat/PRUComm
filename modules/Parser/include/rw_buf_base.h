#ifndef __MODULES_PARSER_RW_BUF_BASE_H__
#define __MODULES_PARSER_RW_BUF_BASE_H__

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

    virtual const unsigned char* get_data_ptr()
    {
        return this->data;
    }

    virtual unsigned int get_data_length()
    {
        return this->data_length;
    }

}


#endif // !__MODULES_PARSER_RW_BUF_BASE_H__