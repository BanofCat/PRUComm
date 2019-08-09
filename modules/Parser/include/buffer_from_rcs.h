#ifndef __MODULES_PARSER_RCS_READER_BUF_H__
#define __MODULES_PARSER_RCS_READER_BUF_H__
#include "rcs2pru_protocol.h"
#include "rw_buf_base.h"


class BufferFromRCS: public RWBufBase
{

public:
    BufferFromRCS();
    ~BufferFromRCS();

    const unsigned char* getRoute();
    const unsigned char* getControlFlag();
    const unsigned char* getID();
    unsigned int getCheckSum();
    unsigned int calculateCheckSum();
    

};  // ! class BufferFromRCS

#endif // !__MODULES_PARSER_RCS_READER_BUF_H__