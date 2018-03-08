/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xtp_api_data_type.h
///@brief ����������ݻ�������
/////////////////////////////////////////////////////////////////////////
#ifndef _XTP_API_DATA_TYPE_H_
#define _XTP_API_DATA_TYPE_H_

#pragma pack(8)

/// ��Ű汾�ŵ��ַ�������
#define XTP_VERSION_LEN 16
/// �汾������
typedef char XTPVersionType[XTP_VERSION_LEN];
/// �ɽ������ַ�������
#define XTP_TRADING_DAY_LEN 9
/// ���֤ȯ������ַ�������
#define XTP_TICKER_LEN 16
/// ���֤ȯ���Ƶ��ַ�������
#define XTP_TICKER_NAME_LEN 64
/// ���ر�����ŵ��ַ�������
#define XTP_LOCAL_ORDER_LEN         11
/// ���������ŵ��ַ�������
#define XTP_ORDER_EXCH_LEN          17
/// �ɽ�ִ�б�ŵ��ַ�������
#define XTP_EXEC_ID_LEN             18
/// ����������Ա�����ַ�������
#define XTP_BRANCH_PBU_LEN          7
/// �û��ʽ��˻����ַ�������
#define XTP_ACCOUNT_NAME_LEN        16

/////////////////////////////////////////////////////////////////////////
///@brief XTP_LOG_LEVEL����־�����������
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_LOG_LEVEL {
	XTP_LOG_LEVEL_FATAL, ///<���ش��󼶱�
	XTP_LOG_LEVEL_ERROR, ///<���󼶱�
	XTP_LOG_LEVEL_WARNING, ///<���漶��
	XTP_LOG_LEVEL_INFO,   ///<info����
	XTP_LOG_LEVEL_DEBUG,  ///<debug����
	XTP_LOG_LEVEL_TRACE   ///<trace����
}XTP_LOG_LEVEL;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_PROTOCOL_TYPE��ͨѶ����Э�鷽ʽ
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_PROTOCOL_TYPE
{
	XTP_PROTOCOL_TCP = 1,	///<����TCP��ʽ����
	XTP_PROTOCOL_UDP		///<����UDP��ʽ���䣨Ŀǰ��δ֧�֣�
}XTP_PROTOCOL_TYPE;



/////////////////////////////////////////////////////////////////////////
///@brief XTP_EXCHANGE_TYPE�ǽ���������
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_EXCHANGE_TYPE
{
	XTP_EXCHANGE_SH = 1,	///<��֤
	XTP_EXCHANGE_SZ,		///<��֤
    XTP_EXCHANGE_UNKNOWN	///<�����ڵĽ���������
}XTP_EXCHANGE_TYPE;

//////////////////////////////////////////////////////////////////////////
///@brief XTP_MARKET_TYPE�г�����
//////////////////////////////////////////////////////////////////////////
typedef enum XTP_MARKET_TYPE
{
    XTP_MKT_INIT = 0,///<��ʼ��ֵ����δ֪
    XTP_MKT_SZ_A = 1,///<����A��
    XTP_MKT_SH_A,    ///<�Ϻ�A��
    XTP_MKT_UNKNOWN   ///<δ֪�����г�����
}XTP_MARKET_TYPE;


/////////////////////////////////////////////////////////////////////////
///@brief XTP_PRICE_TYPE�Ǽ۸�����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_PRICE_TYPE
{
    XTP_PRICE_LIMIT = 1,           ///<�޼۵�-�������ͨ��Ʊҵ���⣬����ҵ���ʹ�ô������ͣ�
    XTP_PRICE_BEST_OR_CANCEL,      ///<��ʱ�ɽ�ʣ��ת�������м۵�-��
    XTP_PRICE_BEST5_OR_LIMIT,      ///<�����嵵��ʱ�ɽ�ʣ��ת�޼ۣ��м۵�-��
    XTP_PRICE_BEST5_OR_CANCEL,     ///<����5����ʱ�ɽ�ʣ��ת�������м۵�-����
    XTP_PRICE_ALL_OR_CANCEL,       ///<ȫ���ɽ�����,�м۵�-��
    XTP_PRICE_FORWARD_BEST,        ///<�������ţ��м۵�-��
    XTP_PRICE_REVERSE_BEST_LIMIT,  ///<�Է�����ʣ��ת�޼ۣ��м۵�-��
    XTP_PRICE_TYPE_UNKNOWN,		   ///<δ֪������Ч�۸�����
}XTP_PRICE_TYPE;



/////////////////////////////////////////////////////////////////////////
///@brief XTP_SIDE_TYPE��������������
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_SIDE_TYPE
{
	XTP_SIDE_BUY = 1,	///<���¹��깺��ETF��ȣ�
	XTP_SIDE_SELL,		///<������ع���
	XTP_SIDE_BUY_OPEN,		///<�򿪣���δ֧�֣�
	XTP_SIDE_SELL_OPEN,		///<��������δ֧�֣�
	XTP_SIDE_BUY_CLOSE,		///<��ƽ����δ֧�֣�
	XTP_SIDE_SELL_CLOSE,	///<��ƽ����δ֧�֣�
	XTP_SIDE_PURCHASE,		///<�깺
	XTP_SIDE_REDEMPTION,	///<���
	XTP_SIDE_SPLIT,			///<���
	XTP_SIDE_MERGE,			///<�ϲ�
    XTP_SIDE_UNKNOWN		///<δ֪������Ч��������
}XTP_SIDE_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_ORDER_ACTION_STATUS_TYPE�Ǳ�������״̬����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_ORDER_ACTION_STATUS_TYPE
{
	XTP_ORDER_ACTION_STATUS_SUBMITTED = 1,	///<�Ѿ��ύ
	XTP_ORDER_ACTION_STATUS_ACCEPTED,		///<�Ѿ�����
	XTP_ORDER_ACTION_STATUS_REJECTED		///<�Ѿ����ܾ�
}XTP_ORDER_ACTION_STATUS_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_ORDER_STATUS_TYPE�Ǳ���״̬����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_ORDER_STATUS_TYPE
{
    XTP_ORDER_STATUS_INIT = 0,///<��ʼ��
    XTP_ORDER_STATUS_ALLTRADED = 1,           ///<ȫ���ɽ�
    XTP_ORDER_STATUS_PARTTRADEDQUEUEING,  ///<���ֳɽ�
    XTP_ORDER_STATUS_PARTTRADEDNOTQUEUEING, ///<���ֳ���
    XTP_ORDER_STATUS_NOTRADEQUEUEING,   ///<δ�ɽ�
    XTP_ORDER_STATUS_CANCELED,  ///<�ѳ���
    XTP_ORDER_STATUS_REJECTED,  ///<�Ѿܾ�
    XTP_ORDER_STATUS_UNKNOWN  ///<δ֪����״̬
}XTP_ORDER_STATUS_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_ORDER_SUBMIT_STATUS_TYPE�Ǳ����ύ״̬����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_ORDER_SUBMIT_STATUS_TYPE
{
    XTP_ORDER_SUBMIT_STATUS_INSERT_SUBMITTED = 1, ///<�����Ѿ��ύ
    XTP_ORDER_SUBMIT_STATUS_INSERT_ACCEPTED,///<�����Ѿ�������
    XTP_ORDER_SUBMIT_STATUS_INSERT_REJECTED,///<�����Ѿ����ܾ�
    XTP_ORDER_SUBMIT_STATUS_CANCEL_SUBMITTED,///<�����Ѿ��ύ
    XTP_ORDER_SUBMIT_STATUS_CANCEL_REJECTED,///<�����Ѿ����ܾ�
    XTP_ORDER_SUBMIT_STATUS_CANCEL_ACCEPTED ///<�����Ѿ�������
}XTP_ORDER_SUBMIT_STATUS_TYPE;


/////////////////////////////////////////////////////////////////////////
///@brief XTP_TE_RESUME_TYPE�ǹ�������������Ӧ���ɽ��ر����ش���ʽ
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_TE_RESUME_TYPE
{
	XTP_TERT_RESTART = 0,	///<�ӱ������տ�ʼ�ش�
	XTP_TERT_RESUME,		///<�Ӵ��ϴ��յ�����������δ֧�֣�
	XTP_TERT_QUICK			///<ֻ���͵�¼��������������Ӧ���ɽ��ر���������
}XTP_TE_RESUME_TYPE;


//////////////////////////////////////////////////////////////////////////
///@brief ETF_REPLACE_TYPE�ֽ������ʶ����
//////////////////////////////////////////////////////////////////////////
typedef enum ETF_REPLACE_TYPE
{
    ERT_CASH_FORBIDDEN = 0,             ///<��ֹ�ֽ����
    ERT_CASH_OPTIONAL,                  ///<�����ֽ����
    ERT_CASH_MUST,                      ///<�����ֽ����
    EPT_INVALID                         ///<��Чֵ
}ETF_REPLACE_TYPE;


//////////////////////////////////////////////////////////////////////////
///@brief XTP_TICKER_TYPE֤ȯ����
//////////////////////////////////////////////////////////////////////////
typedef enum XTP_TICKER_TYPE
{
	XTP_TICKER_TYPE_STOCK = 0,            ///<��ͨ��Ʊ
	XTP_TICKER_TYPE_INDEX,                ///<ָ��
	XTP_TICKER_TYPE_FUND,                 ///<����
	XTP_TICKER_TYPE_BOND,                 ///<ծȯ
	XTP_TICKER_TYPE_UNKNOWN               ///<δ֪����
	
}XTP_TICKER_TYPE;

//////////////////////////////////////////////////////////////////////////
///@brief XTP_BUSINESS_TYPE֤ȯҵ������
//////////////////////////////////////////////////////////////////////////
typedef enum XTP_BUSINESS_TYPE
{
	XTP_BUSINESS_TYPE_CASH = 0,            ///<��ͨ��Ʊҵ�񣨹�Ʊ������ETF�����ȣ�
	XTP_BUSINESS_TYPE_IPOS,                ///<�¹��깺ҵ�񣨶�Ӧ��price type��ѡ���޼����ͣ�
	XTP_BUSINESS_TYPE_REPO,                ///<�ع�ҵ�� ( ��Ӧ��price type��Ϊ�޼ۣ�side��Ϊ�� )
	XTP_BUSINESS_TYPE_ETF,                 ///<ETF����ҵ����δ֧�֣�
	XTP_BUSINESS_TYPE_MARGIN,              ///<������ȯҵ����δ֧�֣�
	XTP_BUSINESS_TYPE_DESIGNATION,         ///<ת�йܣ�δ֧�֣�
	XTP_BUSINESS_TYPE_ALLOTMENT,		   ///<���ҵ�񣨶�Ӧ��price type��ѡ���޼�����,side��Ϊ��
	XTP_BUSINESS_TYPE_STRUCTURED_FUND_PURCHASE_REDEMPTION,	   ///<�ּ���������ҵ��
	XTP_BUSINESS_TYPE_STRUCTURED_FUND_SPLIT_MERGE,	   ///<�ּ������ֺϲ�ҵ��
	XTP_BUSINESS_TYPE_MONEY_FUND,		   ///<���һ���ҵ����δ֧�֣�
	XTP_BUSINESS_TYPE_UNKNOWN              ///<δ֪����

}XTP_BUSINESS_TYPE;

//////////////////////////////////////////////////////////////////////////
///@brief XTP_ACCOUNT_TYPE�˻�����
//////////////////////////////////////////////////////////////////////////
typedef enum XTP_ACCOUNT_TYPE
{
    XTP_ACCOUNT_NORMAL = 0,	///<��ͨ�˻�
    XTP_ACCOUNT_CREDIT,		///<�����˻�
    XTP_ACCOUNT_DERIVE,		///<����Ʒ�˻�
    XTP_ACCOUNT_UNKNOWN		///<δ֪�˻�����
}XTP_ACCOUNT_TYPE;


/////////////////////////////////////////////////////////////////////////
///@brief XTP_FUND_TRANSFER_TYPE���ʽ���ת��������
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_FUND_TRANSFER_TYPE
{
    XTP_FUND_TRANSFER_OUT = 0,		///<ת�� ��XTPת������̨
    XTP_FUND_TRANSFER_IN,	        ///<ת�� �ӹ�̨ת��XTP
    XTP_FUND_TRANSFER_UNKNOWN		///<δ֪����
}XTP_FUND_TRANSFER_TYPE;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_FUND_OPER_STATUS��̨�ʽ�������
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_FUND_OPER_STATUS {
    XTP_FUND_OPER_PROCESSING = 0,	///<XOMS���յ������ڴ�����
    XTP_FUND_OPER_SUCCESS,			///<�ɹ�
    XTP_FUND_OPER_FAILED,			///<ʧ��
    XTP_FUND_OPER_SUBMITTED,		///<���ύ�����й�̨����
    XTP_FUND_OPER_UNKNOWN			///<δ֪
}XTP_FUND_OPER_STATUS;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_SPLIT_MERGE_STATUS��һ���������ֺϲ�״̬����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_SPLIT_MERGE_STATUS {
	XTP_SPLIT_MERGE_STATUS_ALLOW = 0,	///<�����ֺͺϲ�
	XTP_SPLIT_MERGE_STATUS_ONLY_SPLIT,	///<ֻ�����֣�������ϲ�
	XTP_SPLIT_MERGE_STATUS_ONLY_MERGE,	///<ֻ����ϲ�����������
	XTP_SPLIT_MERGE_STATUS_FORBIDDEN	///<�������ֺϲ�
}XTP_SPLIT_MERGE_STATUS;

/////////////////////////////////////////////////////////////////////////
///@brief XTP_TBT_TYPE��һ����ʻر�����
/////////////////////////////////////////////////////////////////////////
typedef enum XTP_TBT_TYPE {
	XTP_TBT_ENTRUST = 1,	///<���ί��
	XTP_TBT_TRADE = 2,		///<��ʳɽ�
}XTP_TBT_TYPE;

/////////////////////////////////////////////////////////////////////////
///TXTPTradeTypeType�ǳɽ���������
/////////////////////////////////////////////////////////////////////////
typedef char TXTPTradeTypeType;

///��ͨ�ɽ�
#define XTP_TRDT_COMMON '0'
///�ֽ����
#define XTP_TRDT_CASH '1'
///һ���г��ɽ�
#define XTP_TRDT_PRIMARY '2'


/////////////////////////////////////////////////////////////////////////
///TXTPOrderTypeType�Ǳ�����������
/////////////////////////////////////////////////////////////////////////
typedef char TXTPOrderTypeType;

///����
#define XTP_ORDT_Normal '0'
///��������
#define XTP_ORDT_DeriveFromQuote '1'
///�������
#define XTP_ORDT_DeriveFromCombination '2'
///��ϱ���
#define XTP_ORDT_Combination '3'
///������
#define XTP_ORDT_ConditionalOrder '4'
///������
#define XTP_ORDT_Swap '5'


#pragma pack()

#endif
