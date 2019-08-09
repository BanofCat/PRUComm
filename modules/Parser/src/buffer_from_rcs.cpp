#include "buffer_from_rcs.h"
#include <string.h>
#include "error_code.h"

BufferFromRCS::
BufferFromRCS()
{
    this->data_length = Rcs2PruProtocol::PROTOCOL_DATA_LEN;
    this->data = new unsigned char[this->data_length];
}

BufferFromRCS::
~BufferFromRCS()
{
    if (this->data != NULL) {
        delete[] this->data;
        this->data = NULL; 
    }
    this->data_length = 0;
}

const unsigned char* BufferFromRCS::
getRoute()
{
    return &this->data[Rcs2PruProtocol::ENCODER_POS];
}

const unsigned char* BufferFromRCS::
getControlFlag()
{
    return &this->data[Rcs2PruProtocol::CONTROL_FLAG_POS];
}

const unsigned char* BufferFromRCS::
getID()
{
    return &this->data[Rcs2PruProtocol::PACKAGE_ID_POS];
}

unsigned int BufferFromRCS::
getCheckSum()
{
    unsigned char check_sum_data[Rcs2PruProtocol::CHECK_SUM_LEN];
    memcpy(check_sum_data, &this->data[Rcs2PruProtocol::CHECK_SUM_POS], sizeof(check_sum_data));
    unsigned int check_sum = *check_sum_data;
    return check_sum;
}

unsigned int BufferFromRCS::
calculateCheckSum()
{
    unsigned int real_check_sum = 0;
    for(int i = Rcs2PruProtocol::ENCODER_POS; i < Rcs2PruProtocol::CHECK_SUM_POS; ++i) {
        real_check_sum += this->data[i];
    }
    return real_check_sum;
}

