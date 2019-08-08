#include "dsp_reader_buf.h"
#include "error_code.h"

DSPReaderBuf::
DSPReaderBuf()
{
    this->data_length = Uart2PruProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

DSPReaderBuf::
~DSPReaderBuf()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; 
    }
    this->data_length = 0;
}

const unsigned char* DSPReaderBuf::
get_head()
{
    return &this->data[Uart2PruProtocol::HEAD_POS];
}

const unsigned char* DSPReaderBuf::
get_timestamp()
{
    return &this->data[Uart2PruProtocol::TIMESTAMP_POS];
}

const unsigned char* DSPReaderBuf::
get_pos()
{
    return &this->data[Uart2PruProtocol::ENCODER_POS];
}

const unsigned char* DSPReaderBuf::
get_protect_code()
{
    return &this->data[Uart2PruProtocol::PROTECTION_POS];
}

const unsigned short* DSPReaderBuf::
get_dsp_version()
{
    unsigned short* protection_ptr = &this->data[Uart2PruProtocol::MASTER_VERSION_POS];
    return *protection_ptr;
}

const unsigned char* DSPReaderBuf::
get_servo_brake()
{
    return &this->data[Uart2PruProtocol::SERVO_BRAKE_POS];
}

const unsigned char* DSPReaderBuf::
get_ack()
{
    return &this->data[Uart2PruProtocol::ACK_POS];
}

const unsigned char* DSPReaderBuf::
get_isr_ticker()
{
    return &this->data[Uart2PruProtocol::ISR_TICKER_POS];
}

const unsigned char* DSPReaderBuf::
get_crc()
{
    return &this->data[Uart2PruProtocol::CRC_POS];
}

const unsigned char* DSPReaderBuf::
get_tail()
{
    return &this->data[Uart2PruProtocol::TAIL_POS];
}
