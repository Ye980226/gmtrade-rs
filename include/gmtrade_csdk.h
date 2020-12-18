
#ifndef GMCSDK_H
#define GMCSDK_H

#include "gmtrade_def.h"

#ifdef WIN32
#ifdef GMSDKC_EXPORTS  
#define GM_API extern "C" __declspec(dllexport)
#else
#define GM_API extern "C" __declspec(dllimport)
#endif
#else
#define GM_API extern "C"
#endif


//基础 API //////////////////////////////////////////////////////////////////////////////

typedef void(*EventCallback)(const char *msg_type, void *data, int data_len);

//设置事件回调, 回调data均为c结构体
GM_API void gmi_set_event_callback(EventCallback cb);

//设置事件回调, 回调data均为protobuf序列化流
GM_API void gmi_set_event_callback_pb(EventCallback cb);

//设置api-key
GM_API int gmi_set_token(const char *token);

//自定义服务地址
GM_API void gmi_set_serv_addr(const char *addr);

//运行策略
GM_API int gmi_run();

//开始运行策略
GM_API int gmi_start();

//实盘模式初始化
GM_API int gmi_init();

//运行策略
GM_API int gmi_poll();

//停止策略
GM_API int gmi_stop();

//获取c-sdk版本号
GM_API const char* gmi_get_c_version();

//根据错误码获取错误信息
GM_API const char* gmi_strerror(int errorno);

//获取扩展错误信息
GM_API const char* gmi_get_ext_errormsg();

GM_API char * gmi_gbk2utf(const char *gbk);
GM_API char * gmi_utf2gbk(const char *utf8);

//设置sdk信息
GM_API void gmi_set_version(const char *sdk_version, const char *sdk_lang, const char *sdk_arch = NULL, const char *sdk_os = NULL);

//定时器
GM_API void gmi_set_timer(int interval);

//交易类 API //////////////////////////////////////////////////////////////////////////////

//设置默认账号
GM_API int gmi_login(const char *account_ids);

//下单委托
GM_API int gmi_place_order(Order *orders, int order_count, int is_combined, Order **res, int *count);

//下单委托 req = core.api.Orders, res = core.api.Orders
GM_API int gmi_place_order_pb(void *req, int req_len, void **res, int *res_len);

//平所有仓位
GM_API int gmi_close_all_positions(const char *account_ids, Order **res, int *count);

//平所有仓位 req = trade.api.CloseAllPositionsReq, res = core.api.Orders
GM_API int gmi_close_all_positions_pb(void *req, int req_len, void **res, int *res_len);

//撤单委托 
GM_API int gmi_cancel_orders(Order *orders, int count);

//撤单委托 req = core.api.Orders
GM_API int gmi_cancel_orders_pb(void *req, int req_len);

//撤销所有委托
GM_API int gmi_cancel_all_orders(const char *account_ids = NULL);

//撤销所有委托 req = trade.api.CancelAllOrdersReq
GM_API int gmi_cancel_all_orders_pb(void *req, int req_len);

//查询委托
GM_API int gmi_get_orders(const char *account, const char *symbols, const char *cl_ord_ids, Order **res, int *count);

//查询委托 req = trade.api.GetOrdersReq, res = core.api.Orders
GM_API int gmi_get_orders_pb(void *req, int req_len, void **res, int *res_len);

//查询未结委托
GM_API int gmi_get_unfinished_orders(const char *account, Order **res, int *count);

//查询未结委托 req = trade.api.GetUnfinishedOrdersReq, res = core.api.Orders
GM_API int gmi_get_unfinished_orders_pb(void *req, int req_len, void **res, int *res_len);

//查询资金
GM_API int gmi_get_cash(const char *account, Cash **cash, int *count);

//查询资金  req = trade.api.GetCashReq, res = core.api.Cashes
GM_API int gmi_get_cash_pb(void *req, int req_len, void **res, int *res_len);

//查询持仓
GM_API int gmi_get_positions(const char *account, const char *symbol, int side, Position **res, int *count);

//查询持仓 req = trade.api.GetPositionsReq, res = core.api.Positions
GM_API int gmi_get_positions_pb(void *req, int req_len, void **res, int *res_len);

//查询成交
GM_API int gmi_get_execution_reports(const char *account, const char *cl_ord_id, int exec_type, ExecRpt **res, int *count);

//查询成交 req = trade.api.GetExecrptsReq, res = core.api.ExecRpts
GM_API int gmi_get_execution_reports_pb(void *req, int req_len, void **res, int *res_len);

//获取交易账户状态
GM_API int gmi_get_account_status(const char *accounts, AccountStatus **res, int *count);

//获取交易账户状态 req = tradegw.api.GetAccountStatusesReq, res = core.api.AccountStatuses
GM_API int gmi_get_account_status_pb(void *req, int req_len, void **res, int *res_len);

#endif
