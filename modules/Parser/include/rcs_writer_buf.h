#ifndef __MODULES_PARSER_RCS_WRITER_BUF_H__
#define __MODULES_PARSER_RCS_WRITER_BUF_H__
#include "pru2rcs_protocol.h"
#include "rw_buf_base.h"

class RCSWriterBuf: public RWBufBase
{

public:
    RCSWriterBuf();
    ~RCSWriterBuf();

    int set_request_counter(unsigned char* data, unsigned int data_size_byte);
    int set_pru_dsp_error(unsigned char* data, unsigned int data_size_byte);
    int set_pru_version(unsigned char* data, unsigned int data_size_byte);
    int set_handshake_status(unsigned char* data, unsigned int data_size_byte);
    int set_run_state(unsigned char* data, unsigned int data_size_byte);
    int set_echo(unsigned char* data, unsigned int data_size_byte);
    int set_check_sum(unsigned char* data, unsigned int data_size_byte);
    int set_pru_timestamp(unsigned char* data, unsigned int data_size_byte);

private:
    int set_data(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte);
    

};  // ! class RCSWriterBuf

#endif // !__MODULES_PARSER_RCS_WRITER_BUF_H__