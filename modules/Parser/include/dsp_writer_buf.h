#ifndef __MODULES_PARSER_DSP_WRITER_BUF_H__
#define __MODULES_PARSER_DSP_WRITER_BUF_H__
#include "pru2uart_protocol.h"

class DSPWriterBuf
{

protected:
    unsigned char data[Pru2UartProtocol::PROTOCOL_DATA_LEN];
    

public:
    int updateData(const unsigned char* data, unsigned int data_size_byte);
    const unsigned char* get_data_ptr();
    unsigned int get_data_length();
    unsigned char* routePos();
    unsigned char* servoBrake();
    const unsigned char& get_software_sto();

};  // ! class DSPWriterBuf

#endif // !__MODULES_PARSER_DSP_WRITER_BUF_H__