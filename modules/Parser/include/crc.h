#ifndef __MODULES_PARSER_CRC_H__
#define __MODULES_PARSER_CRC_H__

class CRC
{
public:
    unsigned short calculateCRC(unsigned char* data, unsigned int data_size_byte);
}


#endif // !__MODULES_PARSER_CRC_H__