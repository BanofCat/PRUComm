#ifndef __MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__
#define __MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__

#include "rcs_device_simulation.h"
#include "buffer_from_rcs.h"
#include "buffer_to_rcs.h"
#include "crc.h"

struct RCSProtocolInfo
{
    unsigned char time_stamp;
    unsigned char id;
    unsigned char request_counter;

    // init
    RCSProtocolInfo()
    {
        timestamp = 0;
        id = 0;
        request_counter = 0;
    }
    
};  // !struct RCSProtocolInfo


class RCSComm
{
private:
    RCSDeviceSimulation rcs_dev;
    CRC crc_obj;
    struct RCSProtocolInfo com_info;
    
    unsigned int ack_err_counter;
    unsigned char last_ack;
    const static int MAX_ACK_ERR = 5;
public:
    int packageWriteData();
    unsigned char getRequestCounter();
    int read(BufferFromRCS* rcs_data_obj);
    int write(BufferToRCS* rcs_data_obj);
}; // ! class RCSComm


#endif // !__MODULES_COMMUNICATOR_RCS_COMMUNICATOR_H__