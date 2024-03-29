#include "buffer_to_dsp.h"
#include "error_code.h"

/* public */

BufferToDSP::
BufferToDSP()
{
    this->data_length = Pru2UartProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

BufferToDSP::
~BufferToDSP()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL;
    }
    this->data_length = 0;
}


int BufferToDSP::
setRoutePos(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::ENCODER_POS, data_size_byte, Pru2UartProtocol::ENCODER_LEN);
}

int BufferToDSP::
setControlFlag(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::SERVO_BRAKE_POS, data_size_byte, Pru2UartProtocol::SERVO_BRAKE_LEN);
}


int BufferToDSP::
setHead(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::HEAD_POS, data_size_byte, Pru2UartProtocol::HEAD_LEN);
}

int BufferToDSP::
setTimestamp(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::TIMESTAMP_POS, data_size_byte, Pru2UartProtocol::TIMESTAMP_LEN);
}

int BufferToDSP::
setIsrTicker(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::ISR_TICKER_POS, data_size_byte, Pru2UartProtocol::ISR_TICKER_LEN);
}

int BufferToDSP::
setAck(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::ACK_POS, data_size_byte, Pru2UartProtocol::ACK_LEN);
}

int BufferToDSP::
setCrc(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::CRC_POS, data_size_byte, Pru2UartProtocol::CRC_LEN);
}

int BufferToDSP::
setTail(unsigned char* data, unsigned int data_size_byte)
{
    return this->setData(data, Pru2UartProtocol::TAIL_POS, data_size_byte, Pru2UartProtocol::TAIL_LEN);
}

/* private */
int BufferToDSP::
setData(unsigned char* data, unsigned int start_pos, unsigned int data_size_byte, unsigned int max_size_byte)
{
    if (data == NULL || data_size_byte > max_size_byte) {
        throwErrorCode(ARGS_INVALID);
    }
    memcpy(&this->data[start_pos], data, data_size_byte);
    return OK;  
}