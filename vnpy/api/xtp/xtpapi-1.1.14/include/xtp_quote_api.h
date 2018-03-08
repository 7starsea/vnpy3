/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xtp_quote_api.h
///@brief �������鶩�Ŀͻ��˽ӿ�
/////////////////////////////////////////////////////////////////////////

#ifndef _XTP_QUOTE_API_H_
#define _XTP_QUOTE_API_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xtp_api_struct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT __declspec(dllimport)
#endif
#else
#define MD_API_EXPORT 
#endif

/*!
* \class XTP::API::QuoteSpi
*
* \brief ����ص���
*
* \author ��̩֤ȯ�ɷ����޹�˾
* \date ʮ�� 2015
*/
namespace XTP {
	namespace API {
		class QuoteSpi
		{
		public:

			///���ͻ����������̨ͨ�����ӶϿ�ʱ���÷��������á�
			///@param reason ����ԭ��������������Ӧ
			///@remark api�����Զ������������߷���ʱ�����û�����ѡ����������������ڴ˺����е���Login���µ�¼��ע���û����µ�¼����Ҫ���¶�������
			virtual void OnDisconnected(int reason) {};


			///����Ӧ��
			///@param error_info ����������Ӧ��������ʱ�ľ���Ĵ������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark �˺���ֻ���ڷ�������������ʱ�Ż���ã�һ�������û�����
			virtual void OnError(XTPRI *error_info) {};

			///��������Ӧ��
			///@param ticker ��ϸ�ĺ�Լ�������
			///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///�˶�����Ӧ��
			///@param ticker ��ϸ�ĺ�Լȡ���������
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///�������֪ͨ��������һ��һ����
			///@param market_data ��������
			///@param bid1_qty ��һ��������
			///@param bid1_count ��һ���е���Чί�б���
			///@param max_bid1_count ��һ������ί�б���
			///@param ask1_qty ��һ��������
			///@param ask1_count ��һ���е���Чί�б���
			///@param max_ask1_count ��һ������ί�б���
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnDepthMarketData(XTPMD *market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count) {};

			///�������鶩����Ӧ��
			///@param ticker ��ϸ�ĺ�Լ�������
			///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///�˶����鶩����Ӧ��
			///@param ticker ��ϸ�ĺ�Լȡ���������
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///���鶩����֪ͨ
			///@param order_book ���鶩�������ݣ���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnOrderBook(XTPOB *order_book) {};

			///�����������Ӧ��
			///@param ticker ��ϸ�ĺ�Լ�������
			///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///�˶��������Ӧ��
			///@param ticker ��ϸ�ĺ�Լȡ���������
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) {};

			///�������֪ͨ
			///@param tbt_data ����������ݣ��������ί�к���ʳɽ�����Ϊ���ýṹ�壬��Ҫ����type�����������ί�л�����ʳɽ�����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnTickByTick(XTPTBT *tbt_data) {};

			///����ȫ�г�������Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnSubscribeAllMarketData(XTPRI *error_info) {};

			///�˶�ȫ�г�������Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnUnSubscribeAllMarketData(XTPRI *error_info) {};

			///����ȫ�г������鶩����Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnSubscribeAllOrderBook(XTPRI *error_info) {};

			///�˶�ȫ�г������鶩����Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnUnSubscribeAllOrderBook(XTPRI *error_info) {};

			///����ȫ�г����������Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnSubscribeAllTickByTick(XTPRI *error_info) {};

			///�˶�ȫ�г����������Ӧ��
			///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ��Ҫ���ٷ���
			virtual void OnUnSubscribeAllTickByTick(XTPRI *error_info) {};


			///��ѯ�ɽ��׺�Լ��Ӧ��
			///@param ticker_info �ɽ��׺�Լ��Ϣ
			///@param error_info ��ѯ�ɽ��׺�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴β�ѯ�ɽ��׺�Լ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			virtual void OnQueryAllTickers(XTPQSI* ticker_info, XTPRI *error_info, bool is_last) {};

			///��ѯ��Լ�����¼۸���ϢӦ��
			///@param ticker_info ��Լ�����¼۸���Ϣ
			///@param error_info ��ѯ��Լ�����¼۸���Ϣʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param is_last �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			virtual void OnQueryTickersPriceInfo(XTPTPI* ticker_info, XTPRI *error_info, bool is_last) {};
		};
	}
}

#ifndef WINDOWS
#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
#endif

/*!
* \class XTP::API::QuoteApi
*
* \brief ���鶩�Ľӿ���
*
* \author ��̩֤ȯ�ɷ����޹�˾
* \date ʮ�� 2015
*/
namespace XTP {
	namespace API {
		class MD_API_EXPORT QuoteApi
		{
		public:
			///����QuoteApi
			///@param client_id ���������룩��������ͬһ�û��Ĳ�ͬ�ͻ��ˣ����û��Զ���
			///@param save_file_path ���������룩����������Ϣ�ļ���Ŀ¼�����趨һ���п�дȨ�޵���ʵ���ڵ�·��
			///@param log_level ��־�������
			///@return ��������UserApi
			///@remark ���һ���˻���Ҫ�ڶ���ͻ��˵�¼����ʹ�ò�ͬ��client_id��ϵͳ����һ���˻�ͬʱ��¼����ͻ��ˣ����Ƕ���ͬһ�˻�����ͬ��client_idֻ�ܱ���һ��session���ӣ�����ĵ�¼��ǰһ��session�����ڼ䣬�޷�����
			static QuoteApi *CreateQuoteApi(uint8_t client_id, const char *save_file_path, XTP_LOG_LEVEL log_level=XTP_LOG_LEVEL_DEBUG);

			///ɾ���ӿڶ�����
			///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
			virtual void Release() = 0;


			///��ȡ��ǰ������
			///@return ��ȡ���Ľ�����
			///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
			virtual const char *GetTradingDay() = 0;

			///��ȡAPI�ķ��а汾��
			///@return ����api���а汾��
			virtual const char* GetApiVersion() = 0;

			///��ȡAPI��ϵͳ����
			///@return ���صĴ�����Ϣ��������Login��Logout�����ġ�ȡ������ʧ��ʱ���ã���ȡʧ�ܵ�ԭ��
			///@remark �����ڵ���api�ӿ�ʧ��ʱ���ã�����loginʧ��ʱ
			virtual XTPRI *GetApiLastError() = 0;

			///���ò���UDP��ʽ����ʱ�Ľ��ջ�������С
			///@remark ��Ҫ��Login֮ǰ���ã�Ĭ�ϴ�С����С���þ�Ϊ64MB���˻����С��λΪMB��������2�Ĵη���������128MB������128��
			virtual void SetUDPBufferSize(uint32_t buff_size) = 0;


			///ע��ص��ӿ�
			///@param spi �����Իص��ӿ����ʵ�������ڵ�¼֮ǰ�趨
			virtual void RegisterSpi(QuoteSpi *spi) = 0;

			///�����������ʱ��������λΪ��
			///@param interval �������ʱ��������λΪ��
			///@remark �˺���������Login֮ǰ����
			virtual void SetHeartBeatInterval(uint32_t interval) = 0;

			///�������顣
			///@return ���Ľӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո� 
			///@param count Ҫ����/�˶�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ���Զ���ͬһ֤ȯ�������Ķ����Լ�������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶�������
			virtual int SubscribeMarketData(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///�˶����顣
			///@return ȡ�����Ľӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո�  
			///@param count Ҫ����/�˶�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ����ȡ������ͬһ֤ȯ�������Ķ����Լ����Ҫ�붩������ӿ�����ʹ��
			virtual int UnSubscribeMarketData(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///�������鶩������
			///@return �������鶩�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո� 
			///@param count Ҫ����/�˶����鶩�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ���Զ���ͬһ֤ȯ�������Ķ����Լ�������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶�������(�ݲ�֧��)
			virtual int SubscribeOrderBook(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///�˶����鶩������
			///@return ȡ���������鶩�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո�  
			///@param count Ҫ����/�˶����鶩�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ����ȡ������ͬһ֤ȯ�������Ķ����Լ����Ҫ�붩�����鶩�����ӿ�����ʹ��
			virtual int UnSubscribeOrderBook(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///����������顣
			///@return �����������ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո�  
			///@param count Ҫ����/�˶����鶩�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ���Զ���ͬһ֤ȯ�������Ķ����Լ�������û���Ϊ����������Ҫ���µ�¼���������������Ҫ���¶�������(�ݲ�֧��)
			virtual int SubscribeTickByTick(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///�˶�������顣
			///@return ȡ�������������ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@param ticker ��ԼID���飬ע���Լ���������'\0'��β���������ո�  
			///@param count Ҫ����/�˶����鶩�����ĺ�Լ����
			///@param exchage_id ����������
			///@remark ����һ����ȡ������ͬһ֤ȯ�������Ķ����Լ����Ҫ�붩���������ӿ�����ʹ��
			virtual int UnSubscribeTickByTick(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///����ȫ�г�������
			///@return ����ȫ�г�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ��ȫ�г��˶�����ӿ�����ʹ��
			virtual int SubscribeAllMarketData() = 0;

			///�˶�ȫ�г�������
			///@return �˶�ȫ�г�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ�붩��ȫ�г�����ӿ�����ʹ��
			virtual int UnSubscribeAllMarketData() = 0;

			///����ȫ�г������鶩����
			///@return ����ȫ�г����鶩�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ��ȫ�г��˶����鶩�����ӿ�����ʹ��
			virtual int SubscribeAllOrderBook() = 0;

			///�˶�ȫ�г������鶩����
			///@return �˶�ȫ�г����鶩�����ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ�붩��ȫ�г����鶩�����ӿ�����ʹ��
			virtual int UnSubscribeAllOrderBook() = 0;

			///����ȫ�г����������
			///@return ����ȫ�г��������ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ��ȫ�г��˶��������ӿ�����ʹ��
			virtual int SubscribeAllTickByTick() = 0;

			///�˶�ȫ�г����������
			///@return �˶�ȫ�г��������ӿڵ����Ƿ�ɹ�����0����ʾ�ӿڵ��óɹ����ǡ�0����ʾ�ӿڵ��ó���
			///@remark ��Ҫ�붩��ȫ�г��������ӿ�����ʹ��
			virtual int UnSubscribeAllTickByTick() = 0;

			///�û���¼����
			///@return ��¼�Ƿ�ɹ�����0����ʾ��¼�ɹ�����-1����ʾ���ӷ�����������ʱ�û����Ե���GetApiLastError()����ȡ������룬��-2����ʾ�Ѵ������ӣ��������ظ���¼�������Ҫ����������logout����-3����ʾ�����д���
			///@param ip ������ip��ַ�����ơ�127.0.0.1��
			///@param port �������˿ں�
			///@param user ��½�û���
			///@param password ��½����
			///@param sock_type ��1������TCP����2������UDP
			///@remark �˺���Ϊͬ������ʽ������Ҫ�첽�ȴ���¼�ɹ������������ؼ��ɽ��к�����������apiֻ����һ������
			virtual int Login(const char* ip, int port, const char* user, const char* password, XTP_PROTOCOL_TYPE sock_type) = 0;


			///�ǳ�����
			///@return �ǳ��Ƿ�ɹ�����0����ʾ�ǳ��ɹ����ǡ�0����ʾ�ǳ�������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@remark �˺���Ϊͬ������ʽ������Ҫ�첽�ȴ��ǳ������������ؼ��ɽ��к�������
			virtual int Logout() = 0;

			///��ȡ��ǰ�����տɽ��׺�Լ
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ��ѯ�ɹ����ǡ�0����ʾ��ѯ���ɹ�
			///@param exchage_id ����������
			virtual int QueryAllTickers(XTP_EXCHANGE_TYPE exchage_id) = 0;

			///��ȡ��Լ�����¼۸���Ϣ
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ��ѯ�ɹ����ǡ�0����ʾ��ѯ���ɹ�
			///@param exchage_id ����������
			virtual int QueryTickersPriceInfo(char *ticker[], int count, XTP_EXCHANGE_TYPE exchage_id) = 0;

			///��ȡ���к�Լ�����¼۸���Ϣ
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ��ѯ�ɹ����ǡ�0����ʾ��ѯ���ɹ�
			virtual int QueryAllTickersPriceInfo() = 0;


		protected:
			~QuoteApi() {};
		};
	}
}

#ifndef WINDOWS
#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif


#endif
