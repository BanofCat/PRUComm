#include "buffer_to_rcs.h"
#include "error_code.h"

/* public */

BufferToRCS::
BufferToRCS()
{
    this->data_length = Pru2RcsProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

BufferToRCS::
~BufferToRCS()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL;
    }
    this->data_length = 0;
}

int BufferToRCS::
setRequestCounter(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::REQ_COUNTER_POS, data_size_byte, Pru2RcsProtocol::REQ_COUNTER_LEN);
}

int BufferToRCS::
setPruDspError(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::PRU_ERROR_FLAG_POS, data_size_byte, Pru2RcsProtocol::PRU_ERROR_FLAG_LEN);
}

int BufferToRCS::
setPruVersion(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::MASTER_VERSION_POS, data_size_byte, Pru2RcsProtocol::MASTER_VERSION_LEN);
}

int BufferToRCS::
setHandshakeStatus(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::HANDSHAKE_STATUS_POS, data_size_byte, Pru2RcsProtocol::HANDSHAKE_STATUS_LEN);
}

int BufferToRCS::
setRunStatus(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::RUN_STATUS_POS, data_size_byte, Pru2RcsProtocol::RUN_STATUS_LEN);
}

int BufferToRCS::
setEcho(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::ECHO_POS, data_size_byte, Pru2RcsProtocol::ECHO_LEN);
}

int BufferToRCS::
setCheckSum(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::PRU_CHECK_SUM_POS, data_size_byte, Pru2RcsProtocol::PRU_CHECK_SUM_LEN);
}

int BufferToRCS::
setPruTimestamp(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2RcsProtocol::TIMESTAMP_POS, data_size_byte, Pru2RcsProtocol::TIMESTAMP_LEN);
}

void BufferToRCS::
generateCheckSum()
{
    unsigned short check_sum = 0;
    for (int i = Pru2RcsProtocol::ENCODER_POS; i < Pru2RcsProtocol::PRU_CHECK_SUM_POS; ++i) {
        check_sum += this->data[i];
    }
    this->setCheckSum((unsigned char*)&check_sum, Pru2RcsProtocol::PRU_CHECK_SUM_LEN);
}

/* private */
int BufferToRCS::
setData(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte)
{
    if (data == NULL || data_size_byte > max_size_byte) {
        throwErrorCode(ARGS_INVALID);
    }
    memcpy(&this->data[start_pos], data, data_size_byte);
    return OK;    
}