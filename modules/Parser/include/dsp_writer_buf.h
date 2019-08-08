#ifndef __MODULES_PARSER_DSP_WRITER_BUF_H__
#define __MODULES_PARSER_DSP_WRITER_BUF_H__
#include "pru2uart_protocol.h"

class DSPWriterBuf
{

public:
    DSPWriterBuf();
    ~DSPWriterBuf();

    int set_head(unsigned char* data, unsigned int data_size_byte);
    int set_timestamp(unsigned char* data, unsigned int data_size_byte);
    int set_route_pos(unsigned char* data, unsigned int data_size_byte);
    int set_isr_ticker(unsigned char* data, unsigned int data_size_byte);
    int set_control_flag(unsigned char* data, unsigned int data_size_byte);
    int set_ack(unsigned char* data, unsigned int data_size_byte);
    int set_crc(unsigned char* data, unsigned int data_size_byte);
    int set_tail(unsigned char* data, unsigned int data_size_byte);

private:
    int set_data(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte);
};  // ! class DSPWriterBuf

#endif // !__MODULES_PARSER_DSP_WRITER_BUF_H__