#include "uart_comm.h"

/* public */

UARTComm::
UARTComm()
{
    this->uart_dev.init(NULL);
}

int UARTComm::
read(BufferFromDSP* dsp_data_obj)
{
    int ret_val = 0;
    unsigned int buf_len = dsp_data_obj->getDataLength();
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
    unsigned short cal_crc = this->crc_obj.calculateCRC(dsp_data_obj->getDataPtr(), dsp_data_obj->getDataLength());
    if (*(dsp_data_obj->getCrc()) != cal_crc) {
        throwErrorCode(R_DSP_CRC_ERR);
    }

    // check head & tail
    if ((*dsp_data_obj->getHead()) != Uart2PruProtocol::HEAD_VALUE) {
        throwErrorCode(R_DSP_HEAD_ERR);
    }
    if (*(dsp_data_obj->getTail()) != Uart2PruProtocol::TAIL_VALUE) {
        throwErrorCode(R_DSP_TAIL_ERR)
    }
    return ret_val;
}

int UARTComm::
write(BufferToDSP* dsp_data_obj)
{
    int ret_val = 0;
    // calculate crc
    unsigned short crc_data = this->crc_obj.calculateCRC(dsp_data_obj->getDataPtr(), dsp_data_obj->getDataLength());
    dsp_data_obj->setCrc((unsigned char*)&crc_data, sizeof(crc_data));

    ret_val = this->uart_dev.write(dsp_data_obj->getDataPtr(), dsp_data_obj->getDataLength());
    if (ret_val < 0) {
        throwErrorCode(W_DSP_FAILED);
    }
    return ret_val;
}