#ifndef __MODULES_EXCEPTION_ERROR_CODE_H__
#define __MODULES_EXCEPTION_ERROR_CODE_H__

#include<sys/time.h>
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
    fprintf(stderr, "[%s][%s][%d]catch error: %d\n", Filename(__FILE__), __FUNCTION__, __LINE__, err_code);  \
    return err_code;                    \
}

enum LogicError
{
    OK = 0x00,
    ARGS_INVALID = 0x01,
}

enum ReadDSPError
{
    OK = 0x00,
    R_DSP_FAILED = 0x01,
    R_DSP_HEAD_ERR = 0x02,
    R_DSP_TAIL_ERR = 0x04,
    R_DSP_CRC_ERR = 0x08,
    R_DSP_CRC_FIX = 0x10,
    R_DSP_ACK_ERR = 0x20,

}


#endif // !__MODULES_EXCEPTION_ERROR_CODE_H__