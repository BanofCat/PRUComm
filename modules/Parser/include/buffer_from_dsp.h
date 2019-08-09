#ifndef __MODULES_PARSER_DSP_READER_BUF_H__
#define __MODULES_PARSER_DSP_READER_BUF_H__
#include "uart2pru_protocol.h"
#include "rw_buf_base.h"

class BufferFromDSP: public RWBufBase
{

public:
    BufferFromDSP();
    ~BufferFromDSP();
    const unsigned char* getHead();
    const unsigned char* getTimestamp();
    const unsigned char* getPos();
    const unsigned char* getProtectCode();
    const unsigned short* getDspVersion();
    const unsigned char* getServoBrake();
    const unsigned char* getAck();
    const unsigned char* getIsrTicker();
    const unsigned char* getCrc();
    const unsigned char* getTail();
    

};  // ! class BufferFromDSP

#endif // !__MODULES_PARSER_DSP_READER_BUF_H__