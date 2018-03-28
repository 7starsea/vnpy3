# -*- coding: utf-8 -*-
import os
from .vnxtptrader import TraderApi


########################################################################
class XtpTdApi(TraderApi):
    """XTP交易API实现"""

    def __init__(self, gateway, conf):
        """API对象的初始化函数
         :param conf: dict with key(userID, password, clientID, softwareKey, tdAddress, tdPort)
        """
        super(XtpTdApi, self).__init__()

        self.gateway = gateway                  # gateway对象
        self.conf = conf

        self.reqID = 0              # 操作请求编号

        self.connectionStatus = False       # 连接状态
        self.loginStatus = False            # 登录状态

        self.sessionID = 0          # 会话编号
        self.orderDict = {}                 # 委托缓存字典

    def onDisconnected(self, session, reason):
        """连接断开"""
        self.connectionStatus = False
        self.loginStatus = False
        self.gateway.tdConnected = False

        content = ('Disconnected from TdXtp. Reason: %s' % reason)
        self.writeLog(content)

        # 发起重新连接
        n = self.login(self.conf['tdAddress'], self.conf['tdPort'], self.conf['userID'], self.conf['password'], 1)

        if n:
            self.sessionID = n
            self.connectionStatus = True
            self.loginStatus = True
            self.writeLog('Connected to TdXtp. SessionID: %s' %n)
        else:
            self.writeLog('Failed connecting to TdXtp!')

    #----------------------------------------------------------------------
    def onError(self, error):
        """错误回报"""
        # log = VtLogData()
        # log.logContent = 'onTdError ErrorId: %d Msg: %s' % (error['error_id'], error['error_msg'])
        # # err.errorID = error['error_id']
        # # err.errorMsg = error['error_msg'].decode('gbk')
        # self.gateway.OnLog(log)
        self.gateway.OnError(error['error_id'], error['error_msg'])

        # err = VtErrorData()
        # err.gatewayName = self.gatewayName
        # err.errorID = error['error_id']
        # err.errorMsg = error['error_msg'].decode('gbk')
        # self.gateway.OnError(err)

    #----------------------------------------------------------------------
    def onOrderEvent(self, data, error, session):
        """委托数据回报"""
        # 错误信息
        if error['error_id']:
            self.gateway.OnError(error['error_id'], error['error_msg'] + " onOrderEvent OrderXtpId:" + str(data['order_xtp_id']))
            # err = VtLogData()
            # err.logContent = 'onOrderEvent ErrorID: %d OrderXtpId: %d' % (error['error_id'], data['order_xtp_id'])
            # err.errorID = error['error_id']
            # err.errorMsg = u'委托号' + str(data['order_xtp_id']) + ':' + error['error_msg'].decode('gbk')
            # err.errorTime = order.orderTime
            # self.gateway.OnLog(err)
        else:
            pass  # # Your implementation

    def onTradeEvent(self, data, session):
        """成交推送"""
        pass  # # Your implementation

    def onCancelOrderError(self, data, error, session):
        """撤单错误回报"""
                # 错误信息
        if error['error_id']:
            self.gateway.OnError(error['error_id'], error['error_msg'] + " onCancelOrderError OrderXtpId:" + str(data['order_xtp_id']))
        else:
            pass  # # Your implementation


    #----------------------------------------------------------------------
    def onQueryOrder(self, data, error, reqid, last, session):
        """委托查询回报"""
        pass

    #----------------------------------------------------------------------
    def onQueryTrade(self, data, error, reqid, last, session):
        """成交查询回报"""
        pass

    #----------------------------------------------------------------------
    def onQueryPosition(self, data, error, reqid, last, session):
        """查询持仓回报"""
        if error['error_id']:
            self.gateway.OnError(error['error_id'], error['error_msg'] + " onQueryPosition.")
            return

        pass  # # Your implementation

        if last:
            print('OnQueryPosition finished success!')
            self.gateway.OnQueryPositionFinished()

    #----------------------------------------------------------------------
    def onQueryAsset(self, data, error, reqid, last, session):
        """账户查询回报"""
        # account = VtAccountData()
        # account.gatewayName = self.gatewayName
        #
        # # 账户代码
        # account.accountID = self.userID
        # account.vtAccountID = '.'.join([self.gatewayName, account.accountID])
        #
        # # 数值相关
        # account.balance = float(data['total_asset'])
        # account.available = float(data['buying_power'])
        # account.commission = float(data['fund_buy_fee']) + float(data['fund_sell_fee'])
        print ('balance %f available %f' % (float(data['total_asset']), float(data['buying_power'])))
        # if last:
        #     print('onQueryAsset finished success!')
        # # 推送
        # # self.gateway.onAccount(account)
        pass

    #----------------------------------------------------------------------
    def onQueryStructuredFund(self, data, error, reqid, last, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryFundTransfer(self, data, error, reqid, last, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onFundTransfer(self, data, error, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryETF(self, data, error, reqid, last, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryETFBasket(self, data, error, reqid, last, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryIPOInfoList(self, data, error, reqid, last, session):
        """"""
        pass

    #----------------------------------------------------------------------
    def onQueryIPOQuotaInfo(self, data, error, reqid, last, session):
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
            self.createTraderApi(self.conf['clientID'], path)

            # 设置软件编码，认证用
            self.setSoftwareKey(self.conf['softwareKey'])

            # 设置订单和成交回报重传模式
            self.subscribePublicTopic(0)

            # 发起登录
            n = self.login(self.conf['tdAddress'], self.conf['tdPort'], self.conf['userID'], self.conf['password'], 1)

            if n:
                self.sessionID = n
                self.connectionStatus = True
                self.loginStatus = True
                self.writeLog('Connected to TdXtp. SessionID: %s.' %n)
            else:
                self.writeLog('Failed connecting to TdXtp!')

    #----------------------------------------------------------------------
    def qryAccount(self):
        """查询账户"""
        if self.sessionID:
            self.reqID += 1
            self.queryAsset(self.sessionID, self.reqID)

    #----------------------------------------------------------------------
    def qryPosition(self):
        """查询持仓"""
        if self.sessionID:
            self.reqID += 1
            self.queryPosition('', self.sessionID, self.reqID)

    #----------------------------------------------------------------------
    def sendOrder(self, req):
        """发单"""
        return self.insertOrder(req, self.sessionID)
        # req = {}
        # req['ticker'] = orderReq.symbol
        # req['price'] = orderReq.price
        # req['quantity'] = orderReq.volume
        # req['price_type'] = priceTypeMap.get(orderReq.priceType, 0)
        # req['market'] = marketMap.get(orderReq.exchange, 0)
        # req['business_type'] = 0        # 目前只支持买卖业务
        #
        # # 目前尚未支持衍生品交易，因此不适用
        # #req['side'] = sideMap.get((orderReq.direction, OFFSET_NONE), 0)
        # if orderReq.direction == DIRECTION_LONG:
        #     req['side'] = 1
        # else:
        #     req['side'] = 2
        #
        # # 发出委托
        # orderID = str(self.insertOrder(req, self.sessionID))
        # vtOrderID = '.'.join([self.gatewayName, orderID])
        #
        # # 返回订单号（字符串），便于某些算法进行动态管理
        # return vtOrderID

    #----------------------------------------------------------------------
    def sendCancel(self, order_xtp_id):
        """撤单，因为cancelOrder的命名已经被原生接口使用了，所以改为sendCancel"""
        return self.cancelOrder(order_xtp_id, self.sessionID)

    #----------------------------------------------------------------------
    def close(self):
        """关闭"""
        self.exit()

    #----------------------------------------------------------------------
    def writeLog(self, content):
        """记录日志"""
        self.gateway.OnLog(content)

