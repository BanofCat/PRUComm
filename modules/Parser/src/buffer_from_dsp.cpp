#include "buffer_from_dsp.h"
#include "error_code.h"

BufferFromDSP::
BufferFromDSP()
{
    this->data_length = Uart2PruProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

BufferFromDSP::
~BufferFromDSP()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; 
    }
    this->data_length = 0;
}

const unsigned char* BufferFromDSP::
getHead()
{
    return &this->data[Uart2PruProtocol::HEAD_POS];
}

const unsigned char* BufferFromDSP::
getTimestamp()
{
    return &this->data[Uart2PruProtocol::TIMESTAMP_POS];
}

const unsigned char* BufferFromDSP::
getPos()
{
    return &this->data[Uart2PruProtocol::ENCODER_POS];
}

const unsigned char* BufferFromDSP::
getProtectCode()
{
    return &this->data[Uart2PruProtocol::PROTECTION_POS];
}

const unsigned short* BufferFromDSP::
getDspVersion()
{
    static unsigned short protection_data;
    memcpy(&protection_data, &this->data[Uart2PruProtocol::MASTER_VERSION_POS], sizeof(protection_data));
    return &protection_data;
}

const unsigned char* BufferFromDSP::
getServoBrake()
{
    return &this->data[Uart2PruProtocol::SERVO_BRAKE_POS];
}

const unsigned char* BufferFromDSP::
getAck()
{
    return &this->data[Uart2PruProtocol::ACK_POS];
}

const unsigned char* BufferFromDSP::
getIsrTicker()
{
    return &this->data[Uart2PruProtocol::ISR_TICKER_POS];
}

const unsigned char* BufferFromDSP::
getCrc()
{
    return &this->data[Uart2PruProtocol::CRC_POS];
}

const unsigned char* BufferFromDSP::
getTail()
{
    return &this->data[Uart2PruProtocol::TAIL_POS];
}
