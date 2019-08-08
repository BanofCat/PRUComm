#ifndef __MODULES_PARSER_RCS_READER_BUF_H__
#define __MODULES_PARSER_RCS_READER_BUF_H__
#include "rcs2pru_protocol.h"
#include "rw_buf_base.h"


class RCSReaderBuf: public RWBufBase
{

public:
    RCSReaderBuf();
    ~RCSReaderBuf();

    const unsigned char* get_route();
    const unsigned char* get_control_flag();
    const unsigned char* get_id();
    const unsigned char* get_check_sum();

    

};  // ! class RCSReaderBuf

#endif // !__MODULES_PARSER_RCS_READER_BUF_H__