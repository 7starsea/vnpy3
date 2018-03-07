//˵������

//API
#include "xtp_quote_api.h"

#include <string>
#include <queue>
#include <vector>

///Boost
///#define BOOST_PYTHON_STATIC_LIB
#include <boost/python/module.hpp>	//python��װ
#include <boost/python/def.hpp>		//python��װ
#include <boost/python/dict.hpp>	//python��װ
#include <boost/python/list.hpp>	//python��װ
#include <boost/python/object.hpp>	//python��װ
#include <boost/python.hpp>			//python��װ
#include <boost/thread.hpp>			//������е��̹߳���
#include <boost/bind.hpp>			//������е��̹߳���


//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;


//����
#define ONDISCONNECTED 1
#define ONERROR 2
#define ONSUBMARKETDATA 3
#define ONUNSUBMARKETDATA 4
#define ONDEPTHMARKETDATA 5
#define ONSUBORDERBOOK 6
#define ONUNSUBORDERBOOK 7
#define ONORDERBOOK 8
#define ONSUBTICKBYTICK 9
#define ONUNSUBTICKBYTICK 10
#define ONTICKBYTICK 11
#define ONSUBSCRIBEALLMARKETDATA 12
#define ONUNSUBSCRIBEALLMARKETDATA 13
#define ONSUBSCRIBEALLORDERBOOK 14
#define ONUNSUBSCRIBEALLORDERBOOK 15
#define ONSUBSCRIBEALLTICKBYTICK 16
#define ONUNSUBSCRIBEALLTICKBYTICK 17
#define ONQUERYALLTICKERS 18
#define ONQUERYTICKERSPRICEINFO 19


///-------------------------------------------------------------------------------------
///API�еĲ������
///-------------------------------------------------------------------------------------

//GILȫ�����򻯻�ȡ�ã�
//���ڰ���C++�̻߳��GIL�����Ӷ���ֹpython����
class PyLock
{
private:
	PyGILState_STATE gil_state;

public:
	//��ĳ�����������д����ö���ʱ�����GIL��
	PyLock()
	{
		gil_state = PyGILState_Ensure();
	}

	//��ĳ��������ɺ����ٸö���ʱ�����GIL��
	~PyLock()
	{
		PyGILState_Release(gil_state);
	}
};


//����ṹ��
struct Task
{
	int task_name;		//�ص��������ƶ�Ӧ�ĳ���
	void *task_data;	//���ݽṹ��
	void *task_error;	//����ṹ��
	int task_id;		//����id
	bool task_last;		//�Ƿ�Ϊ��󷵻�
};


///�̰߳�ȫ�Ķ���
template<typename Data>

class ConcurrentQueue
{
private:
	queue<Data> the_queue;								//��׼�����
	mutable mutex the_mutex;							//boost������
	condition_variable the_condition_variable;			//boost��������

public:

	//�����µ�����
	void push(Data const& data)
	{
		mutex::scoped_lock lock(the_mutex);				//��ȡ������
		the_queue.push(data);							//������д�������
		lock.unlock();									//�ͷ���
		the_condition_variable.notify_one();			//֪ͨ���������ȴ����߳�
	}

	//�������Ƿ�Ϊ��
	bool empty() const
	{
		mutex::scoped_lock lock(the_mutex);
		return the_queue.empty();
	}

	//ȡ��
	Data wait_and_pop()
	{
		mutex::scoped_lock lock(the_mutex);

		while (the_queue.empty())						//������Ϊ��ʱ
		{
			the_condition_variable.wait(lock);			//�ȴ���������֪ͨ
		}

		Data popped_value = the_queue.front();			//��ȡ�����е����һ������
		the_queue.pop();								//ɾ��������
		return popped_value;							//���ظ�����
	}

};


//���ֵ��л�ȡĳ����ֵ��Ӧ������������ֵ������ṹ������ֵ��
void getInt(dict d, string key, int* value);

//���ֵ��л�ȡĳ����ֵ��Ӧ�ĸ�����������ֵ������ṹ������ֵ��
void getDouble(dict d, string key, double* value);

//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ�������ֵ������ṹ������ֵ��
void getChar(dict d, string key, char* value);

//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ���������ֵ������ṹ������ֵ��
void getStr(dict d, string key, char* value);


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class QuoteApi : public XTP::API::QuoteSpi
{
private:
	XTP::API::QuoteApi* api;			//API����
	thread *task_thread;				//�����߳�ָ�루��python���������ݣ�
	ConcurrentQueue<Task*> task_queue;	//�������

public:
	QuoteApi()
	{
		function0<void> f = boost::bind(&QuoteApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~QuoteApi()
	{
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	///���ͻ����������̨ͨ�����ӶϿ�ʱ���÷��������á�
	///@param reason ����ԭ��������������Ӧ
	///@remark api�����Զ������������߷���ʱ�����û�����ѡ����������������ڴ˺����е���Login���µ�¼��ע���û����µ�¼����Ҫ���¶�������
	virtual void OnDisconnected(int reason);


	///����Ӧ��
	///@param error_info ����������Ӧ��������ʱ�ľ���Ĵ������ʹ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark �˺���ֻ���ڷ�������������ʱ�Ż���ã�һ�������û�����
	virtual void OnError(XTPRI *error_info);

	///��������Ӧ��
	///@param ticker ��ϸ�ĺ�Լ�������
	///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last);

	///�˶�����Ӧ��
	///@param ticker ��ϸ�ĺ�Լȡ���������
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last);

	///�������֪ͨ��������һ��һ����
	///@param market_data ��������
	///@param bid1_qty ��һ��������
	///@param bid1_count ��һ���е���Чί�б���
	///@param max_bid1_count ��һ������ί�б���
	///@param ask1_qty ��һ��������
	///@param ask1_count ��һ���е���Чί�б���
	///@param max_ask1_count ��һ������ί�б���
	///@remark ��Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnDepthMarketData(XTPMD *market_data, int64_t bid1_qty[], int32_t bid1_count, int32_t max_bid1_count, int64_t ask1_qty[], int32_t ask1_count, int32_t max_ask1_count);

	///�������鶩����Ӧ��
	///@param ticker ��ϸ�ĺ�Լ�������
	///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last);

	///�˶����鶩����Ӧ��
	///@param ticker ��ϸ�ĺ�Լȡ���������
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last);

	///���鶩����֪ͨ
	///@param order_book ���鶩�������ݣ���Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnOrderBook(XTPOB *order_book);

	///�����������Ӧ��
	///@param ticker ��ϸ�ĺ�Լ�������
	///@param error_info ���ĺ�Լ��������ʱ�Ĵ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴ζ��ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ�����ĵĺ�Լ����Ӧһ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last);

	///�˶��������Ӧ��
	///@param ticker ��ϸ�ĺ�Լȡ���������
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴�ȡ�����ĵ����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	///@remark ÿ��ȡ�����ĵĺ�Լ����Ӧһ��ȡ������Ӧ����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last);

	///�������֪ͨ
	///@param tbt_data ����������ݣ��������ί�к���ʳɽ�����Ϊ���ýṹ�壬��Ҫ����type�����������ί�л�����ʳɽ�����Ҫ���ٷ��أ���������������Ϣ������������ʱ���ᴥ������
	virtual void OnTickByTick(XTPTBT *tbt_data);

	///����ȫ�г�������Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnSubscribeAllMarketData(XTPRI *error_info);

	///�˶�ȫ�г�������Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnUnSubscribeAllMarketData(XTPRI *error_info);

	///����ȫ�г������鶩����Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnSubscribeAllOrderBook(XTPRI *error_info);

	///�˶�ȫ�г������鶩����Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnUnSubscribeAllOrderBook(XTPRI *error_info);

	///����ȫ�г����������Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnSubscribeAllTickByTick(XTPRI *error_info);

	///�˶�ȫ�г����������Ӧ��
	///@param error_info ȡ�����ĺ�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@remark ��Ҫ���ٷ���
	virtual void OnUnSubscribeAllTickByTick(XTPRI *error_info);


	///��ѯ�ɽ��׺�Լ��Ӧ��
	///@param ticker_info �ɽ��׺�Լ��Ϣ
	///@param error_info ��ѯ�ɽ��׺�Լʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴β�ѯ�ɽ��׺�Լ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	virtual void OnQueryAllTickers(XTPQSI* ticker_info, XTPRI *error_info, bool is_last);

	///��ѯ��Լ�����¼۸���ϢӦ��
	///@param ticker_info ��Լ�����¼۸���Ϣ
	///@param error_info ��ѯ��Լ�����¼۸���Ϣʱ��������ʱ���صĴ�����Ϣ����error_infoΪ�գ�����error_info.error_idΪ0ʱ������û�д���
	///@param is_last �Ƿ�˴β�ѯ�����һ��Ӧ�𣬵�Ϊ���һ����ʱ��Ϊtrue�����Ϊfalse����ʾ��������������Ϣ��Ӧ
	virtual void OnQueryTickersPriceInfo(XTPTPI* ticker_info, XTPRI *error_info, bool is_last);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processDisconnected(Task *task);

	void processError(Task *task);

	void processSubMarketData(Task *task);

	void processUnSubMarketData(Task *task);

	void processDepthMarketData(Task *task);

	void processSubOrderBook(Task *task);

	void processUnSubOrderBook(Task *task);

	void processOrderBook(Task *task);

	void processSubTickByTick(Task *task);

	void processUnSubTickByTick(Task *task);

	void processTickByTick(Task *task);

	void processSubscribeAllMarketData(Task *task);

	void processUnSubscribeAllMarketData(Task *task);

	void processSubscribeAllOrderBook(Task *task);

	void processUnSubscribeAllOrderBook(Task *task);

	void processSubscribeAllTickByTick(Task *task);

	void processUnSubscribeAllTickByTick(Task *task);

	void processQueryAllTickers(Task *task);

	void processQueryTickersPriceInfo(Task *task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onDisconnected(int reason) {};

	virtual void onError(dict data) {};

	virtual void onSubMarketData(dict data, dict error, bool last) {};

	virtual void onUnSubMarketData(dict data, dict error, bool last) {};

	virtual void onDepthMarketData(dict data) {};

	virtual void onSubOrderBook(dict data, dict error, bool last) {};

	virtual void onUnSubOrderBook(dict data, dict error, bool last) {};

	virtual void onOrderBook(dict data) {};

	virtual void onSubTickByTick(dict data, dict error, bool last) {};

	virtual void onUnSubTickByTick(dict data, dict error, bool last) {};

	virtual void onTickByTick(dict data) {};

	virtual void onSubscribeAllMarketData(dict error) {};

	virtual void onUnSubscribeAllMarketData(dict error) {};

	virtual void onSubscribeAllOrderBook(dict error) {};

	virtual void onUnSubscribeAllOrderBook(dict error) {};

	virtual void onSubscribeAllTickByTick(dict error) {};

	virtual void onUnSubscribeAllTickByTick(dict error) {};

	virtual void onQueryAllTickers(dict data, dict error, bool last) {};

	virtual void onQueryTickersPriceInfo(dict data, dict error, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createQuoteApi(int clientid, string path);

	void release();

	int exit();

	string getTradingDay();

	string getApiVersion();

	dict getApiLastError();

	void setUDPBufferSize(int size);

	void setHeartBeatInterval(int interval);

	int subscribeMarketData(string ticker, int exchange);

	int unSubscribeMarketData(string ticker, int exchange);

	int subscribeOrderBook(string ticker, int exchange);

	int unSubscribeOrderBook(string ticker, int exchange);

	int subscribeTickByTick(string ticker, int exchange);

	int unSubscribeTickByTick(string ticker, int exchange);

	void subscribeAllMarketData();

	void unSubscribeAllMarketData();

	void subscribeAllOrderBook();

	void unSubscribeAllOrderBook();

	void subscribeAllTickByTick();

	void unSubscribeAllTickByTick();

	int login(string ip, int port, string user, string password, int socktype);

	int logout();

	int queryAllTickers(int exchange);

	int queryTickersPriceInfo(string ticker, int exchange);

	int queryAllTickersPriceInfo();
};
