#include "rcs_writer_buf.h"
#include "error_code.h"

/* public */

RCSWriterBuf::
RCSWriterBuf()
{
    this->data_length = Pru2RcsProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

RCSWriterBuf::
~RCSWriterBuf()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; `
    }
    this->data_length = 0;
}

int RCSWriterBuf::
set_request_counter(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::REQ_COUNTER_POS, data_size_byte, Pru2RcsProtocol::REQ_COUNTER_LEN);
}

int RCSWriterBuf::
set_pru_dsp_error(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::PRU_ERROR_FLAG_POS, data_size_byte, Pru2RcsProtocol::PRU_ERROR_FLAG_LEN);
}

int RCSWriterBuf::
set_pru_version(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::MASTER_VERSION_POS, data_size_byte, Pru2RcsProtocol::MASTER_VERSION_LEN);
}

int RCSWriterBuf::
set_handshake_status(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::HANDSHAKE_STATUS_POS, data_size_byte, Pru2RcsProtocol::HANDSHAKE_STATUS_LEN);
}

int RCSWriterBuf::
set_run_state(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::RUN_STATUS_POS, data_size_byte, Pru2RcsProtocol::RUN_STATUS_LEN);
}

int RCSWriterBuf::
set_echo(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::ECHO_POS, data_size_byte, Pru2RcsProtocol::ECHO_LEN);
}

int RCSWriterBuf::
set_check_sum(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::PRU_CHECK_SUM_POS, data_size_byte, Pru2RcsProtocol::PRU_CHECK_SUM_LEN);
}

int RCSWriterBuf::
set_pru_timestamp(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2RcsProtocol::TIMESTAMP_POS, data_size_byte, Pru2RcsProtocol::TIMESTAMP_LEN);
}


/* private */
int set_data(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte)
{
    if (data == NULL || data_size_byte > max_size_byte) {
        throwErrorCode(ARGS_INVALID);
    }
    memcpy(&this->data[start_pos], data, data_size_byte);
    return OK;    
}