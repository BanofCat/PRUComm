#ifndef __MODULES_PARSER_DSP_READER_BUF_H__
#define __MODULES_PARSER_DSP_READER_BUF_H__
#include "uart2pru_protocol.h"

class DSPReaderBuf
{

public:
    DSPReaderBuf();
    ~DSPReaderBuf();
    const unsigned char* get_head();
    const unsigned char* get_timestamp();
    const unsigned char* get_pos();
    const unsigned char* get_protect_code();
    const unsigned short* get_dsp_version();
    const unsigned char* get_servo_brake();
    const unsigned char* get_ack();
    const unsigned char* get_isr_ticker();
    const unsigned char* get_crc();
    const unsigned char* get_tail();
    

};  // ! class DSPReaderBuf

#endif // !__MODULES_PARSER_DSP_READER_BUF_H__