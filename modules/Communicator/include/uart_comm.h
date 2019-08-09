#ifndef __MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__
#define __MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__

#include "uart_device_simulation.h"
#include "buffer_from_dsp.h"
#include "buffer_to_dsp.h"
#include "crc.h"

struct UARTProtocolInfo
{
    unsigned char time_stamp;
    unsigned char ack;
    unsigned char isr_ticker[];
}


class UARTComm
{
private:
    UartDeviceSimulation uart_dev;
    CRC crc_obj;
    unsigned int ack_err_counter;
    unsigned char last_ack;
    const static int MAX_ACK_ERR = 5;
public:
    int read(BufferFromDSP* dsp_data_obj);
    int write(BufferToDSP* dsp_data_obj);
}


#endif // !__MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__