#include "dsp_writer_buf.h"
#include "error_code.h"

int DSPWriterBuf::
updateData(const unsigned char* data, unsigned int data_size_byte)
{
    if (data_size_byte > sizeof(this->data) || data == NULL) {
        return ARGS_INVALID;
    }
    memcpy(this->data, data, data_size_byte);
    return OK;
}

const unsigned char* DSPWriterBuf::
get_data_ptr()
{
    return this->data;
}

unsigned int DSPWriterBuf::
get_data_length()
{
    return sizeof(this->data);
}

unsigned char* DSPWriterBuf::
routePos()
{
    return &this->data[Pru2UartProtocol::ENCODER_POS];
}

unsigned char* DSPWriterBuf::
servoBrake()
{
    return &this->data[Pru2UartProtocol::SERVO_BRAKE_POS];
}

const unsigned char& DSPWriterBuf::
get_software_sto()
{

}