#ifndef __MODULES_COMMUNICATOR_UART_DEVICE_SIMULATION_H__
#define __MODULES_COMMUNICATOR_UART_DEVICE_SIMULATION_H__
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "uart2pru_protocol.h"
#include "pru2uart_protocol.h"
#include "error_code.h"


class UartDeviceSimulation
{
private:
    unsigned char read_buf[Uart2PruProtocol::PROTOCOL_DATA_LEN];
    unsigned char write_buf[Pru2UartProtocol::PROTOCOL_DATA_LEN];
public:
    int init(void* param) {
        memset(this->read_buf, 0, sizeof(this->read_buf));
        memset(this->write_buf, 0, sizeof(this->write_buf));
        this->read_buf[Uart2PruProtocol::HEAD_POS] = Uart2PruProtocol::HEAD_VALUE;
        this->read_buf[Uart2PruProtocol::TAIL_POS] = Uart2PruProtocol::TAIL_VALUE;
        return 0;
    };

    // 64byte
    int read(unsigned char* read_buf, unsigned int buf_size_byte) {
        this->read_buf[Uart2PruProtocol::TIMESTAMP_POS]++;
        this->read_buf[Uart2PruProtocol::PROTECTION_POS] = 1;
        this->read_buf[Uart2PruProtocol::SERVO_BRAKE_POS] = 2;
        this->read_buf[Uart2PruProtocol::ACK_POS] = 3;
        this->read_buf[Uart2PruProtocol::CRC_POS] = 4;
        memcpy(read_buf, this->read_buf, buf_size_byte);
        printData(read_buf, buf_size_byte, "UART 2 PRU");
        return 0;
    };

    // 160byte
    int write(const unsigned char* write_buf, unsigned int buf_size_byte) {
        memcpy(this->write_buf, write_buf, buf_size_byte);
        memcpy(&this->read_buf[Uart2PruProtocol::ENCODER_POS], &this->write_buf[Pru2UartProtocol::ENCODER_POS], Uart2PruProtocol::ENCODER_LEN);
        
        printData(write_buf, buf_size_byte, "PRU 2 UART");
        return 0;
    };
};


#endif // !__MODULES_COMMUNICATOR_UART_DEVICE_SIMULATION_H__