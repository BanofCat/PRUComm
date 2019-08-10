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
    unsigned char isr_ticker[Uart2PruProtocol::ISR_TICKER_LEN];

    UARTProtocolInfo(unsigned char new_timestamp, unsigned char new_ack, unsigned char* new_ticker)
    {
        time_stamp = new_timestamp;
        ack = new_ack;
        memcpy(isr_ticker, new_ticker, sizeof(isr_ticker));
    }
};  // !struct UARTProtocolInfo


class UARTComm
{
private:
    UartDeviceSimulation uart_dev;
    CRC crc_obj;
    unsigned int ack_err_counter;
    unsigned char last_ack;
    const static int MAX_ACK_ERR = 5;
public:
    UARTComm();
    int read(BufferFromDSP* dsp_data_obj);
    int write(BufferToDSP* dsp_data_obj);
};  // !class UARTComm


#endif // !__MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__