#ifndef __MODULES_PARSER_PRU2UART_PROTOCOL_H__
#define __MODULES_PARSER_PRU2UART_PROTOCOL_H__

// write 160 byte to dsp
class Pru2UartProtocol
{
public:    

// byte pos
const static unsigned int PROTOCOL_DATA_LEN = 160;

const static unsigned int HEAD_POS = 0;   // 固定数值: 0
const static unsigned int HEAD_LEN = 1; 

const static unsigned int TIMESTAMP_POS = HEAD_POS + HEAD_LEN;    // 同个周期内接收到的DSP的TimeStamp
const static unsigned int TIMESTAMP_LEN = 1;

const static unsigned int BLANK_0_POS = TIMESTAMP_POS + TIMESTAMP_LEN;  // 预留位
const static unsigned int BLANK_0_LEN = 1;

const static unsigned int ENCODER_POS = BLANK_0_POS + BLANK_0_LEN;  // 5组机械手运动参考位置
const static unsigned int ENCODER_LEN = 24 * 5;
const static unsigned int ENCODER_STEP_LEN = 4;   // a motor data contains 4 bytes

const static unsigned int BLANK_1_POS = ENCODER_POS + ENCODER_LEN; // 预留位
const static unsigned int BLANK_1_LEN = 12;

const static unsigned int ISR_TICKER_POS = BLANK_1_POS + BLANK_1_LEN;    // 返回接收到的64byte数据里的IsrTicker信息
const static unsigned int ISR_TICKER_LEN = 4;

const static unsigned int BLANK_2_POS = ISR_TICKER_POS + ISR_TICKER_LEN; // 预留位
const static unsigned int BLANK_2_LEN = 16;

const static unsigned int SERVO_BRAKE_POS = BLANK_2_POS + BLANK_2_LEN;  // 手动示教控制信息
const static unsigned int SERVO_BRAKE_LEN = 1;

const static unsigned int ACK_POS = SERVO_BRAKE_POS + SERVO_BRAKE_LEN;  // 应答数据
const static unsigned int ACK_LEN = 1;

const static unsigned int CRC_POS = ACK_POS + ACK_LEN;  // CRC校验和
const static unsigned int CRC_LEN = 2;

const static unsigned int TAIL_POS = CRC_POS + CRC_LEN;   // 固定数值: 255
const static unsigned int TAIL_LEN = 1;


// bit pos
const static unsigned int SERVO_BIT_POS = 0;    // 1表示进入手动示教模式， 0表示关闭手动示教， 恢复伺服状态
const static unsigned int BRAKE_BIT_POS = 1;    // 1表示刹车锁住， 0表示刹车解开
const static unsigned int STO_RESET_BIT_POS = 2;    // 1表示复位信号， 0表示无复位信号
}; // !class Pru2UartProtocol

#endif  // !__MODULES_PARSER_PRU2UART_PROTOCOL_H__