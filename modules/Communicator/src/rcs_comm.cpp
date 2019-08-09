#include "rcs_comm.h"
#include "error_code.h"

int RCSComm::
read(BufferFromRCS* rcs_data_obj)
{
    if (rcs_data_obj == NULL) {
        throwErrorCode(ARGS_INVALID);
    }
    int ret_val = 0;
    unsigned char read_buf[rcs_data_obj->getDataLength()];
    ret_val = this->rcs_dev.read(read_buf, sizeof(read_buf));
    if (ret_val < 0) {
        throwErrorCode(R_RCS_FAILED);
    }

    // update obj with read data
    ret_val = rcs_data_obj->updateData(read_buf, sizeof(read_buf));
    if (ret_val < 0) {
        throwErrorCode(ret_val);
    }

    // check checksum
    if (rcs_data_obj->get_check_sum() != rcs_data_obj->calculateCheckSum()) {
        throwErrorCode(R_RCS_CHECK_SUM_ERR);
    }

    return ret_val;
}

int RCSComm::
write(BufferToRCS* rcs_data_obj)
{
    int ret_val = 0;
    if (rcs_data_obj == NULL) {
        throwErrorCode(ARGS_INVALID);
    }
    rcs_data_obj->generateCheckSum();
    ret_val = this->rcs_dev.write(rcs_data_obj->getDataPtr(), rcs_data_obj->getDataLength());
    if (ret_val < 0) {
        throwErrorCode(W_RCS_FAILED);
    }
    return ret_val;
}
