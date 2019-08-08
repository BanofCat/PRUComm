#include "dsp_writer_buf.h"
#include "error_code.h"

/* public */

DSPWriterBuf::
DSPWriterBuf()
{
    this->data_length = Pru2UartProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

DSPWriterBuf::
~DSPWriterBuf()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; `
    }
    this->data_length = 0;
}


int DSPWriterBuf::
set_route_pos(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::ENCODER_POS, data_size_byte, Pru2UartProtocol::ENCODER_LEN);
}

int DSPWriterBuf::
set_control_flag(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::SERVO_BRAKE_POS, data_size_byte, Pru2UartProtocol::SERVO_BRAKE_LEN);
}


int DSPWriterBuf::
set_head(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::HEAD_POS, data_size_byte, Pru2UartProtocol::HEAD_LEN);
}

int DSPWriterBuf::
set_timestamp(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::TIMESTAMP_POS, data_size_byte, Pru2UartProtocol::TIMESTAMP_LEN);
}

int DSPWriterBuf::
set_isr_ticker(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::ISR_TICKER_POS, data_size_byte, Pru2UartProtocol::ISR_TICKER_LEN);
}

int DSPWriterBuf::
set_ack(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::ACK_POS, data_size_byte, Pru2UartProtocol::ACK_LEN);
}

int DSPWriterBuf::
set_crc(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::CRC_POS, data_size_byte, Pru2UartProtocol::CRC_LEN);
}

int DSPWriterBuf::
set_tail(unsigned char* data, unsigned int data_size_byte)
{
    return this->set_data(data, Pru2UartProtocol::TAIL_POS, data_size_byte, Pru2UartProtocol::TAIL_LEN);
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