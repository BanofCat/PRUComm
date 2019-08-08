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
    if (*(this->dsp_data_obj->get_crc()) != cal_crc) {
        throwErrorCode(R_DSP_CRC_ERR);
    }

    // check head & tail
    if ((*dsp_data_obj->get_head()) != Uart2PruProtocol::HEAD_VALUE) {
        throwErrorCode(R_DSP_HEAD_ERR);
    }
    if (*(dsp_data_obj->get_tail()) != Uart2PruProtocol::TAIL_VALUE) {
        throwErrorCode(R_DSP_TAIL_ERR)
    }

    // check ack
    if (this->last_ack == *(dsp_data_obj->get_ack())) {
        this->ack_err_counter++;
    } else {
        this->ack_err_counter = 0;
        this->last_ack = *(dsp_data_obj->get_ack());
    }
    if (this->ack_err_counter >= MAX_ACK_ERR) {
        throwErrorCode(R_DSP_ACK_ERR);
    }
    return ret_val;
}

int UartCommunicator::
write(DSPWriterBuf* dsp_data_obj)
{
    int ret_val = 0;
    // calculate crc
    unsigned short crc_data = this->crc_object.calculateCRC(dsp_data_obj.get_data_ptr(), this->dsp_data_obj->get_data_length());
    dsp_data_obj->set_crc((unsigned char*)&crc_data);

    
    ret_val = this->uart_dev.write(dsp_data_obj->get_data_ptr(), dsp_data_obj->get_data_length());
    if (ret_val < 0) {
        throwErrorCode(W_DSP_FAILED);
    }
    return ret_val;
}