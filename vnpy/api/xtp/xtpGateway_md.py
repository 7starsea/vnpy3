# -*- coding: utf-8 -*-
import os
from .vnxtpquote import QuoteApi


class XtpMdApi(QuoteApi):
    """XTP行情API实现"""

    def __init__(self, gateway, conf):
        """Constructor
        :param conf: dict with key(userID, password, clientID, mdAddress, mdPort)
        """
        super(XtpMdApi, self).__init__()

        self.gateway = gateway                  # gateway对象
        self.conf = conf

        self.reqID = 0              # 操作请求编号

        self.connectionStatus = False       # 连接状态
        self.loginStatus = False            # 登录状态

        self.subscribedSymbols = dict()      # 已订阅合约代码 key=exchange_id, value=list(tickers)

    def onDisconnected(self, reason):
        """连接断开"""
        self.connectionStatus = False
        self.loginStatus = False

        content = (u'Disconnected from MdXtp. Reason: %s' % reason)
        self.writeLog(content)

        # 重新连接
        n = self.login(self.conf['mdAddress'], self.conf['mdPort'], self.conf['userID'], self.conf['password'], 1)
        if not n:
            self.connectionStatus = True
            self.loginStatus = True
            self.gateway.mdConnected = True
            self.writeLog('Connected to MdXtp!')
        else:
            self.writeLog('Failed connecting to MdXtp. Reason:%s' % n)

    #----------------------------------------------------------------------
    def onError(self, error):
        """错误回报"""
        # log = VtLogData()
        # log.logContent = 'ErrorId: %d Msg: %s' % (error['error_id'], error['error_msg'])
        # # err.errorID = error['error_id']
        # # err.errorMsg = error['error_msg'].decode('gbk')
        self.gateway.OnError(error['error_id'], error['error_msg'])

    #----------------------------------------------------------------------
    def onSubMarketData(self, data, error, last):
        """订阅行情回报"""
        pass

    #----------------------------------------------------------------------
    def onUnSubMarketData(self, data, error, last):
        """退订行情回报"""
        pass

    #----------------------------------------------------------------------
    def onDepthMarketData(self, data):
        """行情推送"""
        # print(data)
        # self.gateway.OnRtnData(data)
        pass

    #----------------------------------------------------------------------
    def onQueryAllTickers(self, data, error, last):
        """合约信息推送"""
        # print (data['ticker'], data['exchange_id'], data['price_tick'], data['ticker_type'])
        self.gateway.onQueryAllTickers(data, error, last)
        pass
        # if error and error['error_id']:
        #     err = VtErrorData()
        #     err.gatewayName = self.gatewayName
        #     err.errorID = error['error_id']
        #     err.errorMsg = error['error_msg'].decode('gbk')
        #     self.gateway.OnError(err)
        #     return
        #
        # contract = VtContractData()
        # contract.gatewayName = self.gatewayName
        #
        # contract.symbol = data['ticker']
        # contract.exchange = exchangeMapReverse.get(data['exchange_id'], EXCHANGE_UNKNOWN)
        # contract.vtSymbol = '.'.join([contract.symbol, contract.exchange])
        #
        # contract.name = data['ticker_name'].decode('UTF-8')
        # contract.size = 1
        # contract.priceTick = data['price_tick']
        # contract.productClass = productClassMapReverse.get(data['ticker_type'], PRODUCT_UNKNOWN)
        #
        # self.gateway.onContract(contract)

    #----------------------------------------------------------------------
    def onSubOrderBook(self, data, error, last):
        """"""
        pass

    #----------------------------------------------------------------------
    def onUnSubOrderBook(self, data, error, last):
        """"""
        pass

    #----------------------------------------------------------------------
    def onOrderBook(self, data):
        """"""
        pass

    #----------------------------------------------------------------------
    def onSubTickByTick(self, data, error, last):
        """"""
        pass

    #----------------------------------------------------------------------
    def onUnSubTickByTick(self, data, error, last):
        """"""
        pass

    #----------------------------------------------------------------------
    def onTickByTick(self, data):
        """"""
        pass

    #----------------------------------------------------------------------
    def onSubscribeAllMarketData(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onUnSubscribeAllMarketData(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onSubscribeAllOrderBook(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onUnSubscribeAllOrderBook(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onSubscribeAllTickByTick(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onUnSubscribeAllTickByTick(self, error):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryTickersPriceInfo(self, data, error, last):
        """"""
        pass

    #----------------------------------------------------------------------
    def connect(self):
        """初始化连接"""
        # 如果尚未建立服务器连接，则进行连接
        if not self.connectionStatus:
            path = os.getcwd() + '/temp/xtp/'
            if not os.path.exists(path):
                os.makedirs(path)
            self.createQuoteApi(self.conf['clientID'], path)

            n = self.login(self.conf['mdAddress'], self.conf['mdPort'], self.conf['userID'], self.conf['password'], 1)
            if not n:
                self.connectionStatus = True
                self.loginStatus = True
                self.gateway.mdConnected = True
                self.writeLog('Connected to MdXtp!')
            else:
                self.writeLog('Failed connecting to MdXtp. Reason:%s' % n)

    #----------------------------------------------------------------------
    def subscribe(self, tickers, exchange_id):
        """
        订阅合约
        :param tickers: list
        :param exchange_id: follows Wind convection
        :return:
        """
        # 这里的设计是，如果尚未登录就调用了订阅方法
        # 则先保存订阅请求，登录完成后会自动订阅
        if exchange_id == 'SZ':
            xtp_exchange_id = XTP_EXCHANGE_SZ
        elif exchange_id == 'SH':
            xtp_exchange_id = XTP_EXCHANGE_SH
        else:
            print("Xtp only supports SZ, SH")
            return

        if self.loginStatus:
            for ticker in tickers:
                self.subscribeMarketData(ticker, xtp_exchange_id)
        if xtp_exchange_id not in self.subscribedSymbols:
            self.subscribedSymbols[xtp_exchange_id] = []
        self.subscribedSymbols[xtp_exchange_id] += tickers

    #----------------------------------------------------------------------
    def close(self):
        """关闭"""
        self.exit()

    #----------------------------------------------------------------------
    def writeLog(self, content):
        """记录日志"""
        self.gateway.OnLog(content)

