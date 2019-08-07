#ifndef __MODULES_PARSER_PRU2UART_PROTOCOL_H__
#define __MODULES_PARSER_PRU2UART_PROTOCOL_H__

// write 160 byte to dsp
class uart2pru_protocol
{
public:    

// byte pos
const static unsigned int PROTOCOL_DATA_LEN = 160;

const static unsigned int HEAD_POS = 0;   // 第0byte, 固定数值: 0
const static unsigned int HEAD_LEN = 1; 

const static unsigned int TIMESTAMP_POS = HEAD_POS + HEAD_LEN;    // 第1byte, 每2ms周期自加1更新, 范围0-0xFF
const static unsigned int TIMESTAMP_LEN = 1;

const static unsigned int BLANK_0_POS = TIMESTAMP_POS + TIMESTAMP_LEN;
const static unsigned int BLANK_0_LEN = 1;

const static unsigned int ENCODER_POS = EMG_FLAG_POS + EMG_FLAG_LEN;  // 第3byte到第26byte, 每个周期通过FPGA读回的MOTOR当前位置信息,每个轴4byte
const static unsigned int ENCODER_LEN = 24 * 5;
const static unsigned int ENCODER_STEP_LEN = 4;   // a motor data contains 4 bytes

const static unsigned int OUTPUT_POS = ENCODER_POS + ENCODER_LEN;   // 第27byte到第38byte, 由PLC发出, 反映PLC IO的控制状态
const static unsigned int OUTPUT_LEN = 4;

const static unsigned int INPUT_POS = OUTPUT_POS + OUTPUT_LEN;  
const static unsigned int INPUT_LEN = 8;

const static unsigned int ISR_TICKER_POS = VERSION_POS + VERSION_LEN;    // 第57byte到第60byte,周期值为每0.1ms自增1, 数值大于40960000000时调回5120
const static unsigned int ISR_TICKER_LEN = 4;

const static unsigned int PLC_MOTOR_1_POS = PROTECTION_POS + PROTECTION_LEN; // 第41byte到第42byte, 由PLC发出,返回PLC控制马达1位置信息(41高9位, 42低8位)
const static unsigned int PLC_MOTOR_1_LEN = 2;

const static unsigned int PLC_MOTOR_2_POS = PLC_MOTOR_1_POS + PLC_MOTOR_1_LEN; // 第43byte到第44byte, 由PLC发出,返回PLC控制马达2位置信息(43高9位, 44低8位)
const static unsigned int PLC_MOTOR_2_LEN = 2;

const static unsigned int IQ_FDB_POS = PLC_MOTOR_2_POS + PLC_MOTOR_2_LEN;   // 第45byte到第53byte, 一到六轴的电流反馈信息
const static unsigned int IQ_FDB_LEN = 9;

const static unsigned int BLANK_POS = IQ_FDB_POS + IQ_FDB_LEN;  // 第54byte到55byte预留位
const static unsigned int BLANK_LEN = 2;


const static unsigned int CHECK_SUM_POS = ISR_TICKER_POS + ISR_TICKER_LEN;  // 第61byte,到第62byte, 教验和, 从第3byte到第60byte求和, 然后取其低十六位
const static unsigned int CHECK_SUM_LEN = 4;

const static unsigned int TAIL_POS = CHECK_SUM_POS + CHECK_SUM_LEN;   // 固定数值: 255
const static unsigned int TAIL_LEN = 1;


// bit pos
const static unsigned int SERVO_CONTROL_POS = 38;
const static unsigned int SERVO_CONTROL_BIT_POS = 7;    // 反映当前控制器的Servo ON/OFF状态, 试教模式(Servo OFF)下为1, 正常伺服状态(Servo ON)下为0
const static unsigned int SERVO_CONTROL_BIT_LEN = 1;

}

#endif  // !__MODULES_PARSER_PRU2UART_PROTOCOL_H__