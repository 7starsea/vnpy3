/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xtp_api_struct_common.h
///@brief ����ҵ�񹫹����ݽṹ
/////////////////////////////////////////////////////////////////////////

#ifndef _XTP_API_STRUCT_COMMON_H_
#define _XTP_API_STRUCT_COMMON_H_

#if defined(_MSC_VER) && _MSC_VER<1600
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#else
#include <stdint.h>
#endif

#include "xtp_api_data_type.h"

#pragma pack(8)

///������Ϣ���ַ�������
#define XTP_ERR_MSG_LEN  124
///��Ӧ��Ϣ
typedef struct XTPRspInfoStruct
{
	///�������
	int32_t	error_id;
	///������Ϣ
	char	error_msg[XTP_ERR_MSG_LEN];
} XTPRI;

#pragma pack()

#endif // !_XTP_API_STRUCT_COMMON_H_
