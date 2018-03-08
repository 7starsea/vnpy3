/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xquote_api_struct.h
///@brief ����������������ݽṹ
/////////////////////////////////////////////////////////////////////////
#ifndef _XQUOTE_API_STRUCT_H_
#define _XQUOTE_API_STRUCT_H_

#include <stdint.h>
#include "xtp_api_data_type.h"

#pragma pack(8)

///ָ���ĺ�Լ
typedef struct XTPSpecificTickerStruct
{
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ������"600000"�������ո���'\0'��β
	char	ticker[XTP_TICKER_LEN];
} XTPST;


///����
typedef struct XTPMarketDataStruct
{
    // ����
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ���������ո���'\0'��β
    char	ticker[XTP_TICKER_LEN];

    // ��Ʊ�ȼ۸�
	///���¼�
	double	last_price;
	///������
	double	pre_close_price;
	///����
	double	open_price;
	///��߼�
	double	high_price;
	///��ͼ�
	double	low_price;
    ///������
    double	close_price;

    // �ڻ�������
    ///��ֲ�����Ŀǰδ��д��
    double	pre_open_interest;
    ///�ֲ�����Ŀǰδ��д��
	double	open_interest;
    ///�ϴν���ۣ�Ŀǰδ��д��
    double	pre_settlement_price;
    ///���ν���ۣ�Ŀǰδ��д��
	double	settlement_price;

	///��ͣ��ۣ�Ŀǰδ��д��
	double	upper_limit_price;
	///��ͣ��ۣ�Ŀǰδ��д��
	double	lower_limit_price;
	///����ʵ�ȣ�Ŀǰδ��д��
	double	pre_delta;
	///����ʵ�ȣ�Ŀǰδ��д��
	double	curr_delta;

    /// ʱ���࣬��ʽΪYYYYMMDDHHMMSSsss
    int64_t data_time;

    // ��������
    ///������Ϊ�ܳɽ�������λ�ɣ��뽻����һ�£�
    int64_t	qty;
    ///�ɽ���Ϊ�ܳɽ�����λԪ���뽻����һ�£�
    double	turnover;
    ///���վ���=(turnover/qty)
    double	avg_price;

    // ������
    ///ʮ�������
    double bid[10];
    ///ʮ��������
    double	ask[10];
    ///ʮ��������
    int64_t	bid_qty[10];
    ///ʮ��������
    int64_t	ask_qty[10];

    // �������ݣ���������Ŀǰδ��д��
    ///�ɽ�����
    int64_t trades_count;
    ///��ǰ����״̬˵��
    char ticker_status[8];
    ///ί����������
    int64_t total_bid_qty;
    ///ί����������
    int64_t total_ask_qty;
    ///��Ȩƽ��ί��۸�
    double ma_bid_price;
    ///��Ȩƽ��ί���۸�
    double ma_ask_price;
    ///ծȯ��Ȩƽ��ί��۸�
    double ma_bond_bid_price;
    ///ծȯ��Ȩƽ��ί���۸�
    double ma_bond_ask_price;
    ///ծȯ����������
    double yield_to_maturity;
    ///ETF��ֵ��ֵ
    double iopv;
    ///ETF�깺����
    int32_t etf_buy_count;
    ///ETF��ر���
    int32_t etf_sell_count;
    ///ETF�깺����
    double etf_buy_qty;
    ///ETF�깺���
    double etf_buy_money;
    ///ETF�������
    double etf_sell_qty;
    ///ETF��ؽ��
    double etf_sell_money;
    ///Ȩִ֤�е�������
    double total_warrant_exec_qty;
    ///Ȩ֤��ͣ�۸�Ԫ��
    double warrant_lower_price;
    ///Ȩ֤��ͣ�۸�Ԫ��
    double warrant_upper_price;
    ///���볷������
    int32_t cancel_buy_count;
    ///������������
    int32_t cancel_sell_count;
    ///���볷������
    double cancel_buy_qty;
    ///������������
    double cancel_sell_qty;
    ///���볷�����
    double cancel_buy_money;
    ///�����������
    double cancel_sell_money;
    ///�����ܱ���
    int64_t total_buy_count;
    ///�����ܱ���
    int64_t total_sell_count;
    ///����ί�гɽ����ȴ�ʱ��
    int32_t duration_after_buy;
    ///����ί�гɽ����ȴ�ʱ��
    int32_t duration_after_sell;
    ///��ί�м�λ��
    int32_t num_bid_orders;
    ///����ί�м�λ��
    int32_t num_ask_orders;
    ///�ɽ�ʱ�䣨UA3113��
    int32_t exec_time;
    ///���б�־��UA103/UA104��
    char is_market_closed[4];
    ///��Լ�ֲ�����UA103��
    double total_position;
    ///��ӯ��1��UA103��
    double pe_ratio1;
    ///��ӯ��2��UA103��
    double pe_ratio2;
} XTPMD;


///��Ʊ���龲̬��Ϣ
typedef struct XTPQuoteStaticInfo {
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ���������ո���'\0'��β
    char    ticker[XTP_TICKER_LEN];
    /// ��Լ����
    char    ticker_name[XTP_TICKER_NAME_LEN];
    /// ��Լ����
	XTP_TICKER_TYPE ticker_type;
    ///������
    double  pre_close_price;
    ///��ͣ���
    double  upper_limit_price;
    ///��ͣ���
    double  lower_limit_price;
	///��С�䶯��λ
	double  price_tick;
    /// ��Լ��С������(��)
    int32_t  buy_qty_unit;
    /// ��Լ��С������(��)
	int32_t sell_qty_unit;
} XTPQSI;


///������
typedef struct OrderBookStruct {
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ���������ո���'\0'��β
    char    ticker[XTP_TICKER_LEN];

    ///���¼�
    double last_price;
    ///������Ϊ�ܳɽ���
    int64_t qty;
    ///�ɽ���Ϊ�ܳɽ����
    double  turnover;
    ///�ɽ�����
    int64_t trades_count;

    // ������
    ///ʮ�������
    double bid[10];
    ///ʮ��������
    double  ask[10];
    ///ʮ��������
    int64_t bid_qty[10];
    ///ʮ��������
    int64_t ask_qty[10];
    /// ʱ����
    int64_t data_time;
} XTPOB;

////////////////////////////////// �������


///���ί��(���������)
struct XTPTickByTickEntrust {
    ///Ƶ������
    int32_t channel_no;
    ///ί�����(��ͬһ��channel_no��Ψһ����1��ʼ����)
    int64_t seq;
    ///ί�м۸�
    double  price;
    ///ί������
    int64_t qty;
    ///'1':��; '2':��; 'G':����; 'F':����
    char  side;
    ///�������: '1': �м�; '2': �޼�; '3': ��������
    char ord_type;
};

///��ʳɽ�
struct XTPTickByTickTrade {
    ///Ƶ������
    int32_t channel_no;
    ///ί�����(��ͬһ��channel_no��Ψһ����1��ʼ����)
    int64_t seq;
    ///�ɽ��۸�
    double price;
    ///�ɽ���
    int64_t qty;
    ///�ɽ����(�������Ͻ���)
    double money;
    ///�򷽶�����
    int64_t bid_no;
    ///����������
    int64_t ask_no;
    /// SH: �����̱�ʶ('B':������; 'S':������; 'N':δ֪)
    /// SZ: �ɽ���ʶ('4':��; 'F':�ɽ�)
    char trade_flag;
};

///���������Ϣ
typedef struct XTPTickByTickStruct {
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ���������ո���'\0'��β
    char ticker[XTP_TICKER_LEN];
    ///Ԥ��
    int64_t seq;
    ///ί��ʱ�� or �ɽ�ʱ��
    int64_t data_time;
    ///ί�� or �ɽ�
    XTP_TBT_TYPE type;

    union {
        XTPTickByTickEntrust entrust;
        XTPTickByTickTrade     trade;
    };
} XTPTBT;


///����ѯ��������Ϣ
typedef struct XTPTickerPriceInfo {
    ///����������
    XTP_EXCHANGE_TYPE exchange_id;
    ///��Լ���루��������������Ϣ���������ո���'\0'��β
    char ticker[XTP_TICKER_LEN];
    ///���¼�
    double last_price;
} XTPTPI;


#pragma pack()

#endif
