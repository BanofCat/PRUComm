#ifndef __MODULES_PARSER_RCS2PRU_PROTOCOL_H__
#define __MODULES_PARSER_RCS2PRU_PROTOCOL_H__

class Pru2RcsProtocol
{
public:
    const static unsigned int PROTOCOL_DATA_LEN = 485;

    const static unsigned int ENCODER_POS = 0;
    const static unsigned int ENCODER_LEN = 480;


    const static unsigned int CONTROL_FLAG_POS = ENCODER_POS + ENCODER_LEN;   // 表示RCS发送给PRU的控制信息：\
                                                                                第0bit 伺服开关， 0开，伺服模式， 1关， 手动示教模式   \
                                                                                第1bit 刹车开关， 0刹车解开， 1刹车锁住  \
                                                                                第2bit STO开关， 0：OFF， 1： ON  
    const static unsigned int CONTROL_FLAG_LEN = 1;

    const static unsigned int PACKAGE_ID_POS = CONTROL_FLAG_POS + CONTROL_FLAG_LEN;   // 表示数据包ID编号， 范围：0-0xFF
    const static unsigned int PACKAGE_ID_LEN = 1;

    const static unsigned int CHECK_SUM_POS = PACKAGE_ID_POS + PACKAGE_ID_LEN;  // 校验和， 为第0byte到第482byte的数据和
    const static unsigned int CHECK_SUM_LEN = 3;

}; // !class Pru2RcsProtocol

#endif  // !__MODULES_PARSER_RCS2PRU_PROTOCOL_H__