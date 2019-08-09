#include "uart_comm.h"

/* public */
int UARTComm::
read(BufferFromDSP* dsp_data_obj)
{
    int ret_val = 0;
    unsigned int buf_len = this->dsp_data_obj->getDataLength();
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
    unsigned short cal_crc = this->crc_object.calculateCRC(this->dsp_data_obj.getDataPtr(), this->dsp_data_obj->getDataLength());
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
    return ret_val;
}

int UARTComm::
write(BufferToDSP* dsp_data_obj)
{
    int ret_val = 0;
    // calculate crc
    unsigned short crc_data = this->crc_object.calculateCRC(dsp_data_obj.getDataPtr(), this->dsp_data_obj->getDataLength());
    dsp_data_obj->set_crc((unsigned char*)&crc_data);

    ret_val = this->uart_dev.write(dsp_data_obj->getDataPtr(), dsp_data_obj->getDataLength());
    if (ret_val < 0) {
        throwErrorCode(W_DSP_FAILED);
    }
    return ret_val;
}