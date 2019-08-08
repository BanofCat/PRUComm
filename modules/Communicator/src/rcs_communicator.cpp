#include "rcs_communicator.h"
#include "error_code.h"

RcsCommunicator::
RcsCommunicator()
{

}

RcsCommunicator::
~RcsCommunicator()
{

}

int RcsCommunicator::
read(RCSReaderBuf* rcs_data_obj)
{
    int ret_val = 0;
    unsigned char read_buf[rcs_data_obj->get_data_length()];
    ret_val = this->rcs_dev.read(read_buf, sizeof(read_buf));
    if (ret_val < 0) {
        throwErrorCode(R_RCS_FAILED);
    }

    ret_val = this->rcs_data_obj->updateData(read_buf, sizeof(read_buf));
    if (ret_val < 0) {
        
    }


}

int RcsCommunicator::
write(RCSWriterBuf* rcs_data_obj)
{

}
