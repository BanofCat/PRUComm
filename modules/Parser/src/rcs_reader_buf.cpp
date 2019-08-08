#include "rcs_reader_buf.h"
#include "error_code.h"

RCSReaderBuf::
RCSReaderBuf()
{
    this->data_length = Rcs2PruProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

RCSReaderBuf::
~RCSReaderBuf()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; 
    }
    this->data_length = 0;
}

const unsigned char* RCSReaderBuf::
get_route()
{
    return &this->data[Rcs2PruProtocol::ENCODER_POS];
}

const unsigned char* RCSReaderBuf::
get_control_flag()
{
    return &this->data[Rcs2PruProtocol::CONTROL_FLAG_POS];
}

const unsigned char* RCSReaderBuf::
get_id()
{
    return &this->data[Rcs2PruProtocol::PACKAGE_ID_POS];
}

const unsigned char* RCSReaderBuf::
get_check_sum()
{
    return &this->data[Rcs2PruProtocol::CHECK_SUM_POS];
}

