#ifndef __MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__
#define __MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "rcs2pru_protocol.h"
#include "pru2rcs_protocol.h"
#include "error_code.h"

class RCSDeviceSimulation
{
private:
    unsigned char read_buf[Rcs2PruProtocol::PROTOCOL_DATA_LEN];
    unsigned char write_buf[Pru2RcsProtocol::PROTOCOL_DATA_LEN];
public:
    int init(void* param) {
        memset(this->read_buf, 0, sizeof(this->read_buf));
        memset(this->write_buf, 0, sizeof(this->write_buf));
        return 0;
    };

    // 485byte
    int read(unsigned char* read_buf, unsigned int buf_size_byte) {
        this->read_buf[Rcs2PruProtocol::CONTROL_FLAG_POS] = 11;
        this->read_buf[Rcs2PruProtocol::PACKAGE_ID_POS] = 12;
        this->read_buf[Rcs2PruProtocol::CHECK_SUM_POS] = 13;
        memcpy(read_buf, this->read_buf, buf_size_byte);
        printData(read_buf, buf_size_byte, "RCS 2 PRU");
        return 0;
    };

    // 73byte
    int write(const unsigned char* write_buf, unsigned int buf_size_byte) {
        memcpy(this->write_buf, write_buf, buf_size_byte);
        printData(write_buf, buf_size_byte, "PRU 2 RCS");
        return 0;
    };
};


#endif // !__MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__