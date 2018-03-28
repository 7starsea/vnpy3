# -*- coding: utf-8 -*-

from .xtpGateway_md import XtpMdApi
from .xtpGateway_td import XtpTdApi

XTP_EXCHANGE_SH = 1  #,	///<上证
XTP_EXCHANGE_SZ = 2  #, ///<深证

########################################################################
class XtpGateway(object):
    """XTP接口"""

    #----------------------------------------------------------------------
    def __init__(self, conf):
        """Constructor"
        :param conf: dict with key(userID, password, clientID, softwareKey, tdAddress, tdPort, mdAddress, mdPort)
        """

        md_conf = dict({k: conf[k] for k in ['userID', 'password', 'clientID', 'mdAddress', 'mdPort']})
        td_conf = dict({k: conf[k] for k in ['userID', 'password', 'clientID', 'softwareKey', 'tdAddress', 'tdPort']})

        self.mdApi = XtpMdApi(self, md_conf)     # 行情API
        self.tdApi = XtpTdApi(self, td_conf)     # 交易API

    def OnLog(self, msg):
        print(msg)

    def OnError(self, error_id, error_msg):
        pass

    def connect(self):
        """连接"""

        # setting = self.conf
        # try:
        #     userID = str(setting['userID'])
        #     password = str(setting['password'])
        #     clientID = int(setting['clientID'])
        #     softwareKey = str(setting['softwareKey'])
        #     tdAddress = str(setting['tdAddress'])
        #     tdPort = int(setting['tdPort'])
        #     mdAddress = str(setting['mdAddress'])
        #     mdPort = int(setting['mdPort'])
        # except KeyError as err:
        #     self.OnLog('Configuration File Misses some configuration, please check. Msg: %s' % err)
        #     return

        # 创建行情和交易接口对象
        self.mdApi.connect()
        self.tdApi.connect()

        # # Steps
        # # 1. 初始化并启动查询
        # # 2. OnQueryPosition 收到 last为true时，调用 OnQueryPositionFinished
        # # 3. 订阅行情
        self.tdApi.qryPosition()
        self.tdApi.qryAccount()

    def OnQueryPositionFinished(self):
        """
        We may want subscribe market data here; see mdApi.subscribe
        """
        pass

    def close(self):
        """关闭"""
        self.mdApi.close()
        self.tdApi.close()

    def onQueryAllTickers(self, data, error, last):
        print(data)
        if last:
            print('>>> queryAllTickers is done!!!')
        pass

    def queryAllTickers(self, exchange_id):
        # # 查询合约信息
        #         self.queryAllTickers(XTP_EXCHANGE_SH)         # 上交所
        #         self.queryAllTickers(XTP_EXCHANGE_SZ)         # 深交所
        if exchange_id == XTP_EXCHANGE_SH:
            self.mdApi.queryAllTickers(XTP_EXCHANGE_SH)
        elif exchange_id == XTP_EXCHANGE_SZ:
            self.mdApi.queryAllTickers(XTP_EXCHANGE_SZ)
        else:
            self.OnLog('>>> Invalid exchanged_id in queryAllTickers!!!')


if __name__ == '__main__':

    import json
    with open('XTP_connect.json', 'r') as fp:
        xtp_conf = json.load(fp)
    print(xtp_conf)

    xtp = XtpGateway(xtp_conf)
    xtp.connect()
    while True:
        continue
