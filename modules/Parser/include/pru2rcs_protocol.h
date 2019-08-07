#ifndef __MODULES_PARSER_PRU2RCS_PROTOCOL_H__
#define __MODULES_PARSER_PRU2RCS_PROTOCOL_H__

#include "uart2pru_protocol.h"

class Pru2RcsProtocol: public Uart2PruProtocol
{
public:
    const static unsigned int PROTOCOL_DATA_LEN = 73;

    const static unsigned int REQ_COUNTER_POS = TAIL_POS + TAIL_LEN;   // 表示PRU向RCS请求新数据包计数器，范围：0-0xFF，当计数器值与上一次不一致时表示新的数据包请求
    const static unsigned int REQ_COUNTER_LEN = 1;

    const static unsigned int PRU_ERROR_FLAG_POS = REQ_COUNTER_POS + REQ_COUNTER_LEN;   // PRU与DSP数据检测异常代码     \
                                                                                            0x00 正常                 \
                                                                                            0x01 读取DSP数据包长度失败  \
                                                                                            0x02 读取DSP数据包头异常    \
                                                                                            0x04 读取DSP数据包尾异常    \
                                                                                            0x08 读取DSP数据包CRC校验异常， PRU修复数据包成功   \
                                                                                            0x10 读取DSP数据包CRC校验异常， PRU修复数据包失败   \
                                                                                            0x20 PRU读取DSP数据连续5个周期包ACK未改变
    const static unsigned int PRU_ERROR_FLAG_LEN = 1;

    const static unsigned int MASTER_VERSION_POS = PRU_ERROR_FLAG_POS + PRU_ERROR_FLAG_LEN; // PRU主版本号
    const static unsigned int MASTER_VERSION_LEN = 1;

    const static unsigned int BRANCH_VERSION_POS = MASTER_VERSION_POS + MASTER_VERSION_LEN; // PRU从版本号
    const static unsigned int BRANCH_VERSION_LEN = 1;

    const static unsigned int HANDSHAKE_STATUS_POS = BRANCH_VERSION_POS + BRANCH_VERSION_LEN;   // 表示PRU处于握手阶段的状态：\
                                                                                                    0x00 正常               \
                                                                                                    0x01 与RCS握手时读取RPMSG数据超时   \
                                                                                                    0x02 与RCS握手时读取RPMSG数据包错误 \
                                                                                                    0x04 与DSP握手时读取UART连续读取数据失败 \
                                                                                                    0x08 与DSP握手时读取UART数据包解析失败
    const static unsigned int HANDSHAKE_STATUS_LEN = 1;

    const static unsigned int RUN_STATUS_POS = HANDSHAKE_STATUS_POS + HANDSHAKE_STATUS_LEN; // 表示PRU运行过程的状态：  \
                                                                                                0x00 正常           \
                                                                                                0x01 PRU从RCS读取RPMSG数据超时 \
                                                                                                0x02 PRU从RCS读取RPMSG数据错误  \
                                                                                                0x04 PRU向RCS请求数据后，获取数据包ID未更新 \
                                                                                                0x08 PRU从DSP读取UART连续读取数据失败   \
                                                                                                0x10 PRU从DSP读取UART数据包解析失败
    const static unsigned int RUN_STATUS_LEN = 1;

    const static unsigned int ECHO_POS = RUN_STATUS_POS + RUN_STATUS_LEN;   // 表示PRU回馈给RCS上一次数据ID， 范围：0-0xFF
    const static unsigned int ECHO_LEN = 1;

    const static unsigned int PRU_CHECK_SUM_POS = ECHO_POS + ECHO_LEN;  // 校验和， 为第0byte到第71byte的数据和
    const static unsigned int PRU_CHECK_SUM_LEN = 2;

}; // !class Pru2RcsProtocol

#endif  // !__MODULES_PARSER_PRU2RCS_PROTOCOL_H__