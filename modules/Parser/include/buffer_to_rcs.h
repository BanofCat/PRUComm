#ifndef __MODULES_PARSER_RCS_WRITER_BUF_H__
#define __MODULES_PARSER_RCS_WRITER_BUF_H__
#include "pru2rcs_protocol.h"
#include "rw_buf_base.h"

class BufferToRCS: public RWBufBase
{

public:
    BufferToRCS();
    ~BufferToRCS();

    int setRequestCounter(unsigned char* data, unsigned int data_size_byte);
    int setPruDspError(unsigned char* data, unsigned int data_size_byte);
    int setPruVersion(unsigned char* data, unsigned int data_size_byte);
    int setHandshakeStatus(unsigned char* data, unsigned int data_size_byte);
    int setRunStatus(unsigned char* data, unsigned int data_size_byte);
    int setEcho(unsigned char* data, unsigned int data_size_byte);
    int setCheckSum(unsigned char* data, unsigned int data_size_byte);
    int setPruTimestamp(unsigned char* data, unsigned int data_size_byte);
    void generateCheckSum();

private:
    int setData(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte);
    

};  // ! class BufferToRCS

#endif // !__MODULES_PARSER_RCS_WRITER_BUF_H__