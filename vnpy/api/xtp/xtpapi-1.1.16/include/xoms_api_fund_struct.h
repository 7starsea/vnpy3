/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xoms_api_fund_struct.h
///@brief �����ʽ𻮲���ؽṹ������
/////////////////////////////////////////////////////////////////////////
#ifndef XOMS_API_FUND_STRUCT_H_
#define XOMS_API_FUND_STRUCT_H_

#include "xtp_api_data_type.h"
#include "xoms_api_struct.h"
#include "xtp_api_struct_common.h"


#define XTP_ACCOUNT_PASSWORD_LEN 64

/////////////////////////////////////////////////////////////////////////
///�û��ʽ�����
/////////////////////////////////////////////////////////////////////////
struct XTPFundTransferReq
{
    ///�ʽ���ת��ţ������û���д��������xtp_id
    uint64_t	serial_id;
	///�ʽ��˻�����
	char        fund_account[XTP_ACCOUNT_NAME_LEN];
	///�ʽ��˻�����
	char	    password[XTP_ACCOUNT_PASSWORD_LEN];
	///���
	double	    amount;
	///��ת����
	XTP_FUND_TRANSFER_TYPE	transfer_type;

};

/////////////////////////////////////////////////////////////////////////
///�û��ʽ�ת�������Ӧ-�����ʽ�֪ͨ�ṹ��
/////////////////////////////////////////////////////////////////////////
typedef struct XTPFundTransferNotice XTPFundTransferAck ;



#endif