#ifndef __MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__
#define __MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__

#include "uart_device_simulation.h"
#include "dsp_reader_buf.h"
#include "dsp_writer_buf.h"
#include "crc.h"

class UartCommunicator
{
private:
    UartDeviceSimulation uart_dev;
    CRC crc_obj;
    unsigned int ack_err_counter;
    unsigned char last_ack;
    const static int MAX_ACK_ERR = 5;
public:
    UartCommunicator();
    ~UartCommunicator();
    int read(DSPReaderBuf* dsp_data_obj);
    int write(const DSPWriterBuf* dsp_data_obj);
}


#endif // !__MODULES_COMMUNICATOR_UART_COMMUNICATOR_H__