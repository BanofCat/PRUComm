#ifndef __MODULES_PARSER_DSP_WRITER_BUF_H__
#define __MODULES_PARSER_DSP_WRITER_BUF_H__
#include "pru2uart_protocol.h"
#include "rw_buf_base.h"

class BufferToDSP: public RWBufBase
{

public:
    BufferToDSP();
    ~BufferToDSP();

    int setHead(unsigned char* data, unsigned int data_size_byte);
    int setTimestamp(unsigned char* data, unsigned int data_size_byte);
    int setRoutePos(unsigned char* data, unsigned int data_size_byte);
    int setIsrTicker(unsigned char* data, unsigned int data_size_byte);
    int setControlFlag(unsigned char* data, unsigned int data_size_byte);
    int setAck(unsigned char* data, unsigned int data_size_byte);
    int setCrc(unsigned char* data, unsigned int data_size_byte);
    int setTail(unsigned char* data, unsigned int data_size_byte);

private:
    int setData(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte);
};  // ! class BufferToDSP

#endif // !__MODULES_PARSER_DSP_WRITER_BUF_H__