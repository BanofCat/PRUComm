#ifndef __MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__
#define __MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__

class RCSDeviceSimulation
{
private:
      
public:
    int init(void* param) {return 0};
    int read(unsigned char* read_buf, unsigned int buf_size_byte) {return 0};
    int write(const unsigned char* write_buf, unsigned int buf_size_byte) {return 0};
}


#endif // !__MODULES_COMMUNICATOR_RCS_DEVICE_SIMULATION_H__