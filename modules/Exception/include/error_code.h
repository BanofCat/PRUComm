#ifndef __MODULES_EXCEPTION_ERROR_CODE_H__
#define __MODULES_EXCEPTION_ERROR_CODE_H__

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#define PrintTime_s()                   \
        {                               \
            struct timeval tv;          \
            gettimeofday(&tv, NULL);    \
            char tmp[64];               \
            strftime(tmp, sizeof(tmp), "[%Y-%m-%d %H:%M:%S", localtime(&tv.tv_sec));    \
            fprintf(stderr, "%s.%ld]", tmp, tv.tv_usec);                                \
        }

#define Str(x) #x

#define FILE_NAME(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#define throwErrorCode(err_code)        \
{                                       \
    PrintTime_s();                      \
    fprintf(stderr, "[%s][%s][%d]catch error: %x\n", FILE_NAME(__FILE__), __FUNCTION__, __LINE__, err_code);  \
    return err_code;                    \
}

enum LogicError
{
    OK = 0x00,
    ARGS_INVALID = 0x01,
};

enum ReadDSPError
{
    R_DSP_OK = 0x00,
    R_DSP_FAILED = 0x01,
    R_DSP_HEAD_ERR = 0x02,
    R_DSP_TAIL_ERR = 0x04,
    R_DSP_CRC_ERR = 0x08,
    R_DSP_CRC_FIX = 0x10,
    R_DSP_ACK_ERR = 0x20,

};

enum WriteDSPError
{
    W_DSP_OK = 0x00,
    W_DSP_FAILED = 0x01,
};

enum ReadRCSError
{
    R_RCS_OK = 0x00,
    R_RCS_CHECK_SUM_ERR = 0x01,
    R_RCS_ID_ERR = 0x02,
    R_RCS_FAILED = 0x10,
    
};

enum WriteRCSError
{
    W_RCS_OK = 0x00,
    W_RCS_FAILED = 0x01,
};

static void printData(const unsigned char* data, unsigned int len, std::string title, unsigned int next_line=10)
{
    fprintf(stderr, "\n===%s: start===\n", title.c_str());
    for(int i = 0; i < len; ++i) {
        if(i % next_line == 0) {
            fprintf(stderr, "\n");
        }
        fprintf(stderr, "%u\t\t", data[i]);
    }
    fprintf(stderr, "\n---%s: end---\n\n", title.c_str());
};

#endif // !__MODULES_EXCEPTION_ERROR_CODE_H__