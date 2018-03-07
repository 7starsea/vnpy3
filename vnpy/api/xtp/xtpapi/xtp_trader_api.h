/////////////////////////////////////////////////////////////////////////
///@author ��̩֤ȯ�ɷ����޹�˾
///@file xtp_trader_api.h
///@brief ����ͻ��˽��׽ӿ�
/////////////////////////////////////////////////////////////////////////

#ifndef _XTP_TRADER_API_H_
#define _XTP_TRADER_API_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xtp_api_struct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

/*!
* \class XTP::API::TraderSpi
*
* \brief ���׽ӿ���Ӧ��
*
* \author ��̩֤ȯ�ɷ����޹�˾
* \date ʮ�� 2015
*/
namespace XTP {
	namespace API {

		class TraderSpi
		{
		public:

			///���ͻ��˵�ĳ�������뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á�
			///@param reason ����ԭ��������������Ӧ
			///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
			///@remark �û���������logout���µĶ��ߣ����ᴥ���˺�����api�����Զ������������߷���ʱ�����û�����ѡ����������������ڴ˺����е���Login���µ�¼��������session_id����ʱ�û��յ������ݸ�����֮ǰ��������
			virtual void OnDisconnected(uint64_t session_id, int reason) {};

			///����Ӧ��
			///@param error_info ����������Ӧ��������ʱ�ľ���Ĵ������ʹ�����Ϣ,��error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark �˺���ֻ���ڷ�������������ʱ�Ż���ã�һ�������û�����
			virtual void OnError(XTPRI *error_info) {};

			///����֪ͨ
			///@param order_info ������Ӧ������Ϣ���û�����ͨ��order_info.order_xtp_id����������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����order_info.qty_left�ֶ��ڶ���Ϊδ�ɽ������ɡ�ȫ�ɡ��ϵ�״̬ʱ����ʾ�˶�����û�гɽ����������ڲ�����ȫ��״̬ʱ����ʾ�˶���������������order_info.order_cancel_xtp_idΪ������Ӧ�ĳ���ID����Ϊ0ʱ��ʾ�˵������ɹ�
			///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ÿ�ζ���״̬����ʱ�����ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ��ڶ���δ�ɽ���ȫ���ɽ���ȫ�����������ֳ������Ѿܾ���Щ״̬ʱ������Ӧ�����ڲ��ֳɽ�����������ɶ����ĳɽ��ر�������ȷ�ϡ����е�¼�˴��û��Ŀͻ��˶����յ����û��Ķ�����Ӧ
			virtual void OnOrderEvent(XTPOrderInfo *order_info, XTPRI *error_info, uint64_t session_id) {};

			///�ɽ�֪ͨ
			///@param trade_info �ɽ��ر��ľ�����Ϣ���û�����ͨ��trade_info.order_xtp_id����������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ����������Ͻ�����exec_id����Ψһ��ʶһ�ʳɽ���������2�ʳɽ��ر�ӵ����ͬ��exec_id���������Ϊ�˱ʽ����Գɽ��ˡ����������exec_id��Ψһ�ģ���ʱ�޴��жϻ��ơ�report_index+market�ֶο������Ψһ��ʶ��ʾ�ɽ��ر���
			///@remark �����гɽ�������ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û��ĳɽ��ر�����ض���Ϊ����״̬����Ҫ�û�ͨ���ɽ��ر��ĳɽ�������ȷ����OnOrderEvent()�������Ͳ���״̬��
			virtual void OnTradeEvent(XTPTradeReport *trade_info, uint64_t session_id) {};

			///����������Ӧ
			///@param cancel_info ����������Ϣ������������order_cancel_xtp_id�ʹ�������order_xtp_id
			///@param error_info �������ܾ����߷�������ʱ�������ʹ�����Ϣ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߣ���error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ����Ӧֻ���ڳ�����������ʱ���ص�
			virtual void OnCancelOrderError(XTPOrderCancelInfo *cancel_info, XTPRI *error_info, uint64_t session_id) {};

			///�����ѯ������Ӧ
			///@param order_info ��ѯ����һ������
			///@param error_info ��ѯ����ʱ��������ʱ�����صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryOrder(XTPQueryOrderRsp *order_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�ɽ���Ӧ
			///@param trade_info ��ѯ����һ���ɽ��ر�
			///@param error_info ��ѯ�ɽ��ر���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ����֧�ַ�ʱ�β�ѯ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryTrade(XTPQueryTradeRsp *trade_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯͶ���ֲ߳���Ӧ
			///@param position ��ѯ����һֻ��Ʊ�ĳֲ����
			///@param error_info ��ѯ�˻��ֲַ�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark �����û����ܳ��ж����Ʊ��һ����ѯ������ܶ�Ӧ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryPosition(XTPQueryStkPositionRsp *position, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�ʽ��˻���Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param asset ��ѯ�����ʽ��˻����
			///@param error_info ��ѯ�ʽ��˻���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryAsset(XTPQueryAssetRsp *asset, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�ּ�������Ϣ��Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param fund_info ��ѯ���ķּ��������
			///@param error_info ��ѯ�ּ�����������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryStructuredFund(XTPStructuredFundInfo *fund_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�ʽ𻮲�������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param fund_transfer_info ��ѯ�����ʽ��˻����
			///@param error_info ��ѯ�ʽ��˻���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�ʽ𻮲�֪ͨ
			///@param fund_transfer_info �ʽ𻮲�֪ͨ�ľ�����Ϣ���û�����ͨ��fund_transfer_info.serial_id����������ͨ��GetClientIDByXTPID() == client_id�������Լ��Ķ�����
			///@param error_info �ʽ𻮲��������ܾ����߷�������ʱ�������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@remark ���ʽ𻮲�������״̬�仯��ʱ�򣬻ᱻ���ã���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ�����ߡ����е�¼�˴��û��Ŀͻ��˶����յ����û����ʽ𻮲�֪ͨ��
			virtual void OnFundTransfer(XTPFundTransferNotice *fund_transfer_info, XTPRI *error_info, uint64_t session_id) {};

			///�����ѯETF�嵥�ļ�����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param etf_info ��ѯ����ETF�嵥�ļ����
			///@param error_info ��ѯETF�嵥�ļ���������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryETF(XTPQueryETFBaseRsp *etf_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯETF��Ʊ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param etf_component_info ��ѯ����ETF��Լ����سɷֹ���Ϣ
			///@param error_info ��ѯETF��Ʊ����������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryETFBasket(XTPQueryETFComponentRsp *etf_component_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�����¹��깺��Ϣ�б����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param ipo_info ��ѯ���Ľ����¹��깺��һֻ��Ʊ��Ϣ
			///@param error_info ��ѯ�����¹��깺��Ϣ�б�������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryIPOInfoList(XTPQueryIPOTickerRsp *ipo_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

			///�����ѯ�û��¹��깺�����Ϣ����Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			///@param quota_info ��ѯ�����û�ĳ���г��Ľ����¹��깺�����Ϣ
			///@param error_info ���ѯ�û��¹��깺�����Ϣ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
			///@param request_id ����Ϣ��Ӧ������Ӧ������ID
			///@param is_last ����Ϣ��Ӧ�����Ƿ�Ϊrequest_id������������Ӧ�����һ����Ӧ����Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
			///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
			virtual void OnQueryIPOQuotaInfo(XTPQueryIPOQuotaRsp *quota_info, XTPRI *error_info, int request_id, bool is_last, uint64_t session_id) {};

		};
	}
}

#ifndef WINDOWS
#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
#endif

/*!
* \class XTP::API::TraderApi
*
* \brief ���׽ӿ���
*
* \author ��̩֤ȯ�ɷ����޹�˾
* \date ʮ�� 2015
*/
namespace XTP {
	namespace API {

		class TRADER_API_EXPORT TraderApi
		{
		public:
			///����TraderApi
			///@param client_id ���������룩�ͻ���id����������ͬһ�û��Ĳ�ͬ�ͻ��ˣ����û��Զ���
			///@param save_file_path ���������룩����������Ϣ�ļ���Ŀ¼�����趨һ����ʵ���ڵ��п�дȨ�޵�·��
			///@param log_level ��־�������
			///@return ��������UserApi
			///@remark ���һ���˻���Ҫ�ڶ���ͻ��˵�¼����ʹ�ò�ͬ��client_id��ϵͳ����һ���˻�ͬʱ��¼����ͻ��ˣ����Ƕ���ͬһ�˻�����ͬ��client_idֻ�ܱ���һ��session���ӣ�����ĵ�¼��ǰһ��session�����ڼ䣬�޷����ӡ�ϵͳ��֧�ֹ�ҹ����ȷ��ÿ�쿪��ǰ��������
			static TraderApi *CreateTraderApi(uint8_t client_id, const char *save_file_path, XTP_LOG_LEVEL log_level = XTP_LOG_LEVEL_DEBUG);

			///ɾ���ӿڶ�����
			///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
			virtual void Release() = 0;

			///��ȡ��ǰ������
			///@return ��ȡ���Ľ�����
			///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
			virtual const char *GetTradingDay() = 0;

			///ע��ص��ӿ�
			///@param spi �����Իص��ӿ����ʵ�������ڵ�¼֮ǰ�趨
			virtual void RegisterSpi(TraderSpi *spi) = 0;

			///��ȡAPI��ϵͳ����
			///@return ���صĴ�����Ϣ��������Login��InsertOrder��CancelOrder����ֵΪ0ʱ���ã���ȡʧ�ܵ�ԭ��
			///@remark �����ڵ���api�ӿ�ʧ��ʱ���ã�����loginʧ��ʱ
			virtual XTPRI *GetApiLastError() = 0;

			///��ȡAPI�ķ��а汾��
			///@return ����api���а汾��
			virtual const char* GetApiVersion() = 0;

			///ͨ��������xtpϵͳ�е�ID��ȡ�µ��Ŀͻ���id
			///@return ���ؿͻ���id�������ô˷��������Լ��µĶ���
			///@param order_xtp_id ������xtpϵͳ�е�ID
			///@remark ����ϵͳ����ͬһ�û��ڲ�ͬ�ͻ����ϵ�¼������ÿ���ͻ���ͨ����ͬ��client_id��������
			virtual uint8_t GetClientIDByXTPID(uint64_t order_xtp_id) = 0;

			///ͨ��������xtpϵͳ�е�ID��ȡ����ʽ��˻���
			///@return �����ʽ��˻���
			///@param order_xtp_id ������xtpϵͳ�е�ID
			///@remark ֻ���ʽ��˻���¼�ɹ���,���ܵõ���ȷ����Ϣ
			virtual const char* GetAccountByXTPID(uint64_t order_xtp_id) = 0;

			///���Ĺ�������
			///@param resume_type ��������������Ӧ���ɽ��ر����ش���ʽ  
			///        XTP_TERT_RESTART:�ӱ������տ�ʼ�ش�
			///        XTP_TERT_RESUME:(�����ֶΣ��˷�ʽ��δ֧��)���ϴ��յ�������
			///        XTP_TERT_QUICK:ֻ���͵�¼�󹫹���������
			///@remark �÷���Ҫ��Login����ǰ���á����������򲻻��յ������������ݡ�ע�����û����ߺ�������ǳ���login()�����������ķ�ʽ���������á��û�ֻ���յ����ߺ��������Ϣ�������logout()��login()����ô���������ķ�ʽ�������ã��û��յ������ݻ�����û���ѡ��ʽ������
			virtual void SubscribePublicTopic(XTP_TE_RESUME_TYPE resume_type) = 0;

			///������������汾��
			///@param version �û���������汾�ţ���api���а汾�ţ����Ȳ�����15λ����'\0'��β
			///@remark �˺���������Login֮ǰ���ã���ʶ���ǿͻ��˰汾�ţ�������API�İ汾�ţ����û��Զ���
			virtual void SetSoftwareVersion(const char* version) = 0;

			///�����������Key
			///@param key �û��������Key���û����뿪��ʱ���裬��'\0'��β
			///@remark �˺���������Login֮ǰ����
			virtual void SetSoftwareKey(const char* key) = 0;

			///�����������ʱ��������λΪ��
			///@param interval �������ʱ��������λΪ��
			///@remark �˺���������Login֮ǰ����
			virtual void SetHeartBeatInterval(uint32_t interval) = 0;

			///�û���¼����
			///@return session_id�������ʽ��˺ŵ�¼�Ƿ�ɹ�����0����ʾ��¼ʧ�ܣ����Ե���GetApiLastError()����ȡ������룬�ǡ�0����ʾ��¼�ɹ�����ʱ��Ҫ��¼���������ֵsession_id�����¼���ʽ��˻���Ӧ
			///@param ip ��������ַ�����ơ�127.0.0.1��
			///@param port �������˿ں�
			///@param user ��¼�û���
			///@param password ��¼����
			///@param sock_type ��1������TCP����2������UDP��Ŀǰ��ʱֻ֧��TCP
			///@remark �˺���Ϊͬ������ʽ������Ҫ�첽�ȴ���¼�ɹ������������ؼ��ɽ��к�����������api��֧�ֶ���˻����ӣ�����ͬһ���˻�ͬһ��client_idֻ����һ��session���ӣ�����ĵ�¼��ǰһ��session�����ڼ䣬�޷�����
			virtual uint64_t Login(const char* ip, int port, const char* user, const char* password, XTP_PROTOCOL_TYPE sock_type) = 0;


			///�ǳ�����
			///@return �ǳ��Ƿ�ɹ�����0����ʾ�ǳ��ɹ�����-1����ʾ�ǳ�ʧ��
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			virtual int Logout(uint64_t session_id) = 0;

			///����¼������
			///@return ������XTPϵͳ�е�ID,���Ϊ��0����ʾ��������ʧ�ܣ���ʱ�û����Ե���GetApiLastError()����ȡ������룬�ǡ�0����ʾ�������ͳɹ����û���Ҫ��¼�·��ص�order_xtp_id������֤һ����������Ψһ����ͬ�Ľ����ղ���֤Ψһ��
			///@param order ����¼����Ϣ������order.order_client_id�ֶ����û��Զ����ֶΣ��û�����ʲôֵ��������ӦOnOrderEvent()����ʱ�ͻ����ʲôֵ�������ڱ�ע�������û��Լ���λ��������Ȼ�������ʲô�����Ҳ�ǿ��Եġ�order.order_xtp_id�ֶ������û���д��order.ticker���벻���ո���'\0'��β
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@remark ���������ն����󣬻��ڱ�����Ӧ����OnOrderEvent()�з��ر���δ�ɽ���״̬��֮�����еĶ���״̬�ı䣨���˲���״̬������ͨ��������Ӧ��������
			virtual uint64_t InsertOrder(XTPOrderInsertInfo *order, uint64_t session_id) = 0;

			///������������
			///@return ������XTPϵͳ�е�ID,���Ϊ��0����ʾ��������ʧ�ܣ���ʱ�û����Ե���GetApiLastError()����ȡ������룬�ǡ�0����ʾ�������ͳɹ����û���Ҫ��¼�·��ص�order_cancel_xtp_id������֤һ����������Ψһ����ͬ�Ľ����ղ���֤Ψһ��
			///@param order_xtp_id ��Ҫ������ί�е���XTPϵͳ�е�ID
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@remark ��������ɹ������ڱ�����Ӧ����OnOrderEvent()�ﷵ��ԭ����������ȫ������Ϣ��������ɹ�������OnCancelOrderError()��Ӧ�����з��ش���ԭ��
			virtual uint64_t CancelOrder(const uint64_t order_xtp_id, uint64_t session_id) = 0;

			///���ݱ���ID�����ѯ����
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param order_xtp_id ��Ҫ��ѯ�ı�����xtpϵͳ�е�ID����InsertOrder()�ɹ�ʱ���ص�order_xtp_id
			///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryOrderByXTPID(const uint64_t order_xtp_id, uint64_t session_id, int request_id) = 0;

			///�����ѯ����
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ�Ķ������ɸѡ���������к�Լ�������Ϊ�գ���Ĭ�����д��ڵĺ�Լ���룬�����Ϊ�գ��벻���ո񣬲���'\0'��β��������ʼʱ���ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰ������0�㣬����ʱ���ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰʱ��
			///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			///@remark �÷���֧�ַ�ʱ�β�ѯ�������Ʊ����Ϊ�գ���Ĭ�ϲ�ѯʱ����ڵ����б����������ѯʱ��������и���Ʊ������صı������˺�����ѯ���Ľ�����ܶ�Ӧ�����ѯ�����Ӧ
			virtual int QueryOrders(const XTPQueryOrderReq *query_param, uint64_t session_id, int request_id) = 0;

			///����ί�б�������ѯ��سɽ�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param order_xtp_id ��Ҫ��ѯ��ί�б�ţ���InsertOrder()�ɹ�ʱ���ص�order_xtp_id
			///@param session_id �ʽ��˻���Ӧ��session_id����¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			///@remark �˺�����ѯ���Ľ�����ܶ�Ӧ�����ѯ�����Ӧ
			virtual int QueryTradesByXTPID(const uint64_t order_xtp_id, uint64_t session_id, int request_id) = 0;

			///�����ѯ�ѳɽ�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ�ĳɽ��ر�ɸѡ���������к�Լ�������Ϊ�գ���Ĭ�����д��ڵĺ�Լ���룬�����Ϊ�գ��벻���ո񣬲���'\0'��β��������ʼʱ���ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰ������0�㣬����ʱ���ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰʱ��
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			///@remark �÷���֧�ַ�ʱ�β�ѯ�������Ʊ����Ϊ�գ���Ĭ�ϲ�ѯʱ����ڵ����гɽ��ر��������ѯʱ��������и���Ʊ������صĳɽ��ر����˺�����ѯ���Ľ�����ܶ�Ӧ�����ѯ�����Ӧ
			virtual int QueryTrades(XTPQueryTraderReq *query_param, uint64_t session_id, int request_id) = 0;

			///�����ѯͶ���ֲ߳�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param ticker ��Ҫ��ѯ�ĳֲֺ�Լ���룬����Ϊ�գ������Ϊ�գ��벻���ո񣬲���'\0'��β
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			///@remark �÷�������û��ṩ�˺�Լ���룬����ѯ�˺�Լ�ĳֲ���Ϣ�������Լ����Ϊ�գ���Ĭ�ϲ�ѯ���гֲ���Ϣ
			virtual int QueryPosition(const char *ticker, uint64_t session_id, int request_id) = 0;

			///�����ѯ�ʲ�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryAsset(uint64_t session_id, int request_id) = 0;

			///�����ѯ�ּ�����
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ�ķּ�����ɸѡ����������ĸ����������Ϊ�գ���Ĭ�����д��ڵ�ĸ���������Ϊ�գ��벻���ո񣬲���'\0'��β�����н����г�����Ϊ��
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			///@remark �˺�����ѯ���Ľ�����ܶ�Ӧ�����ѯ�����Ӧ
			virtual int QueryStructuredFund(XTPQueryStructuredFundInfoReq *query_param, uint64_t session_id, int request_id) = 0;

			///�ʽ𻮲�����
			///@return �ʽ𻮲�������XTPϵͳ�е�ID,���Ϊ��0����ʾ��Ϣ����ʧ�ܣ���ʱ�û����Ե���GetApiLastError()����ȡ������룬�ǡ�0����ʾ��Ϣ���ͳɹ����û���Ҫ��¼�·��ص�serial_id������֤һ����������Ψһ����ͬ�Ľ����ղ���֤Ψһ��
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			virtual uint64_t FundTransfer(XTPFundTransferReq *fund_transfer, uint64_t session_id) = 0;

			///�����ѯ�ʽ𻮲�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ���ʽ𻮲�����ɸѡ����������serial_id����Ϊ0����Ĭ�������ʽ𻮲������������Ϊ0���������ض����ʽ𻮲�����
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryFundTransfer(XTPQueryFundTransferLogReq *query_param, uint64_t session_id, int request_id) = 0;

			///�����ѯETF�嵥�ļ�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ��ETF�嵥�ļ���ɸѡ���������к�Լ�������Ϊ�գ���Ĭ�����д��ڵ�ETF��Լ���룬market�ֶ�Ҳ����Ϊ��ʼֵ����Ĭ�������г���ETF��Լ
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryETF(XTPQueryETFBaseReq *query_param, uint64_t session_id, int request_id) = 0;

			///�����ѯETF��Ʊ��
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param query_param ��Ҫ��ѯ��Ʊ���ĵ�ETF��Լ�����к�Լ���벻����Ϊ�գ�market�ֶ�Ҳ����ָ��
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryETFTickerBasket(XTPQueryETFComponentReq *query_param, uint64_t session_id, int request_id) = 0;

			///�����ѯ�����¹��깺��Ϣ�б�
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryIPOInfoList(uint64_t session_id, int request_id) = 0;

			///�����ѯ�û��¹��깺�����Ϣ
			///@return ��ѯ�Ƿ�ɹ�����0����ʾ�ɹ����ǡ�0����ʾ������ʱ�û����Ե���GetApiLastError()����ȡ�������
			///@param session_id �ʽ��˻���Ӧ��session_id,��¼ʱ�õ�
			///@param request_id �����û���λ��ѯ��Ӧ��ID�����û��Զ���
			virtual int QueryIPOQuotaInfo(uint64_t session_id, int request_id) = 0;


		protected:
			~TraderApi() {};
		};

			}
}

#ifndef WINDOWS
#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif


#endif
