#ifndef __MODULES_PARSER_UART2PRU_PROTOCOL_H__
#define __MODULES_PARSER_UART2PRU_PROTOCOL_H__

// read 64 byte from DSP
class Uart2PruProtocol
{
public:    

// byte pos
const static unsigned int PROTOCOL_DATA_LEN = 64;

const static unsigned int HEAD_POS = 0;   // 固定数值: 0
const static unsigned int HEAD_LEN = 1;
const static unsigned int HEAD_VALUE = 0;

const static unsigned int TIMESTAMP_POS = HEAD_POS + HEAD_LEN;    // 每2ms周期自加1更新, 范围0-0xFF
const static unsigned int TIMESTAMP_LEN = 1;

const static unsigned int EMG_FLAG_POS = TIMESTAMP_POS + TIMESTAMP_LEN; // DSP数据接收状态, 正常值为0,            \
                                                                            多种错误下数值叠加, 每2ms周期检查数据接收情况更新为0   \
                                                                            0x01 表示 DSP接收数据头尾有误                      \
                                                                            0x02 表示 PC与DSP两边的timestamp对不上             \
                                                                            0x04 表示 CheckSum有错                           \
                                                                            0x08 表示 接收160bytes所用时间超过1.1ms,存在数据接收不完整的可能
const static unsigned int EMG_FLAG_LEN = 1;

const static unsigned int ENCODER_POS = EMG_FLAG_POS + EMG_FLAG_LEN;  // 第3byte到第26byte, 每个周期通过FPGA读回的MOTOR当前位置信息,每个轴4byte
const static unsigned int ENCODER_LEN = 24;
const static unsigned int ENCODER_STEP_LEN = 4;   // a motor data contains 4 bytes

const static unsigned int PROTECTION_POS = ENCODER_POS + ENCODER_LEN;   // 十进制保护信息计算: 第40byte * 256 + 第39byte
const static unsigned int PROTECTION_LEN = 10;

const static unsigned int MASTER_VERSION_POS = PROTECTION_POS + PROTECTION_LEN;  // DSP主程序版本信息
const static unsigned int MASTERVERSION_LEN = 1;

const static unsigned int BRANCH_VERSION_POS = MASTER_VERSION_POS + MASTERVERSION_LEN;  // DSP从程序版本信息
const static unsigned int BRANCH_VERSION_LEN = 1;

const static unsigned int OCP_GPIO_POS = BRANCH_VERSION_POS + BRANCH_VERSION_LEN;
const static unsigned int OCP_GPIO_LEN = 1;

const static unsigned int BLANK_1_POS = OCP_GPIO_POS + OCP_GPIO_LEN;  // 预留位
const static unsigned int BLANK_1_LEN = 5;

const static unsigned int IQ_FDB_POS = BLANK_1_POS + BLANK_1_LEN;   // 一到六轴的电流反馈信息
const static unsigned int IQ_FDB_LEN = 9;

const static unsigned int SERVO_BRAKE_POS = IQ_FDB_POS + IQ_FDB_LEN;   // 牵引示教控制信息
const static unsigned int SERVO_BRAKE_LEN = 1;

const static unsigned int ACK_POS = SERVO_BRAKE_POS + SERVO_BRAKE_LEN;   // 应答数据
const static unsigned int ACK_LEN = 1;

const static unsigned int BLANK_2_POS = ACK_POS + ACK_LEN;  // 预留位
const static unsigned int BLANK_2_LEN = 1;

const static unsigned int ISR_TICKER_POS = BLANK_2_POS + BLANK_2_LEN;    // 周期值为每0.1ms自增1, 数值大于40960000000时调回5120
const static unsigned int ISR_TICKER_LEN = 4;

const static unsigned int CRC_POS = ISR_TICKER_POS + ISR_TICKER_LEN;  // CRC校验
const static unsigned int CRC_LEN = 2;

const static unsigned int TAIL_POS = CRC_POS + CRC_LEN;   // 固定数值: 255
const static unsigned int TAIL_LEN = 1;
const static unsigned int TAIL_VALUE = 255;


// bit pos
const static unsigned int SERVO_BIT_POS = 0;    // 1表示进入手动示教模式， 0表示关闭手动示教， 恢复伺服状态
const static unsigned int BRAKE_BIT_POS = 1;    // 1表示刹车锁住， 0表示刹车解开
const static unsigned int SOFT_STO_BIT_POS = 2;    // 1表示STO异常， 机械手急停， 0表示STO正常
const static unsigned int HARD_STO_BIT_POS = 3;    // 1表示STO硬件开关ON， 0表示硬件开关OFF


}; // !Uart2PruProtocol

#endif  // !__MODULES_PARSER_UART2PRU_PROTOCOL_H__