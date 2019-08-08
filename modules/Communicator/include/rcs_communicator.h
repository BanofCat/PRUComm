#ifndef __MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__
#define __MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__

#include "rcs_device_communicator.h"
#include "rcs_reader_buf.h"
#include "rcs_writer_buf.h"
#include "crc.h"

class RcsCommunicator
{
private:
    RCSDeviceSimulation rcs_dev;
    CRC crc_obj;
    unsigned int ack_err_counter;
    unsigned char last_ack;
    const static int MAX_ACK_ERR = 5;
public:
    RcsCommunicator();
    ~RcsCommunicator();
    int read(RCSReaderBuf* rcs_data_obj);
    int write(RCSWriterBuf* rcs_data_obj);
}


#endif // !__MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__