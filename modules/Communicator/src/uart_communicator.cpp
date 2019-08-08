#include "uart_communicator.h"

/* public */
UartCommunicator::
UartCommunicator()
{
    this->last_ack = 0;
    this->ack_err_counter = 0;
}

UartCommunicator::
~UartCommunicator()
{

}


int UartCommunicator::
read(DSPReaderBuf* dsp_data_obj)
{
    int ret_val = 0;
    unsigned int buf_len = this->dsp_data_obj->get_data_length();
    unsigned char read_buf[buf_len];
    ret_val = this->uart_dev.read(read_buf, buf_len);
    if (ret_val < 0) {
        throwErrorCode(R_DSP_FAILED);
    }
    ret_val = dsp_data_obj->updateData(read_buf, buf_len);
    if (ret_val < 0) {
        throwErrorCode(ret_val);
    }

    // check CRC
    unsigned short cal_crc = this->crc_object.calculateCRC(this->dsp_data_obj.get_data_ptr(), this->dsp_data_obj->get_data_length());
    if (*(this->crc_obj.get_crc()) != cal_crc) {
        throwErrorCode(CRC_ERR);
    }

    // check ack
    if (this->last_ack == dsp_data_obj->get_ack()) {
        this->ack_err_counter++;
    } else {
        this->ack_err_counter = 0
        this->last_ack = dsp_data_obj->get_ack();
    }
    if (this->ack_err_counter >= MAX_ACK_ERR) {
        throwErrorCode(R_DSP_ACK_ERR);
    }

    // check head & tail
    

    // 

    return ret_val;
}

int UartCommunicator::
write(const DSPWriterBuf* dsp_data_obj)
{

}