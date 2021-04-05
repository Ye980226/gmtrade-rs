pub mod module;
use std::os::raw::{c_void,c_char,c_int,c_double,c_longlong};
use std::ptr::{null_mut,null};
use cxx::let_cxx_string;
use cxx::UniquePtr;

use cxx::{type_id, ExternType};
//gmtrade_csdk.h
type EventCallback=extern fn(msg_type:*const u8,data:*const c_void,data_len:c_int);
const LEN_TRADE_SYMBOL:usize=32;
const LEN_ID:usize=64;
const LEN_NAME:usize=64;
const LEN_INFO:usize=128;
const NULL:*const c_void=0 as *const c_void;
#[repr(C)]
struct Order
{
	strategy_id:[c_char;LEN_ID],                      
	account_id:[c_char;LEN_ID],                       
	account_name:[c_char;LEN_NAME],                   
	cl_ord_id:[c_char;LEN_ID],                        
	order_id:[c_char;LEN_ID],                         
	ex_ord_id:[c_char;LEN_ID],                        

	symbol:[c_char;LEN_TRADE_SYMBOL],                       
	side:c_int,                                     
	position_effect:c_int,                          
    position_side:c_int,                            
	order_type:c_int,                               
	order_duration:c_int,                           
	order_qualifier:c_int,                          
	order_src:c_int,                               
	status:c_int,                                   
	ord_rej_reason:c_int,                           
	ord_rej_reason_detail:[c_char;LEN_INFO],          
	price:c_double,                               
	stop_price:c_double,                               
	order_style:c_int,                              
	volume:c_longlong,                                   
	value:c_double,                                    
	percent:c_double,                                  
	target_volume:c_longlong,                            
	target_value:c_double,                             
	target_percent:c_double,                           
	filled_volume:c_longlong,                            
	filled_vwap:c_double,                              
	filled_amount:c_double,                            
	filled_commission:c_double,                        
	created_at:c_longlong,                               
	updated_at:c_longlong,                               
}
unsafe impl ExternType for Order {
    type Id = type_id!("Order");
    type Kind = cxx::kind::Trivial;
}

//gmtrade_def.h
//gmtrade.h
#[cxx::bridge]
mod ffi{


    extern "C++"{
        include!("gmtrade/include/gmtrade_def.h");
        type OrderStatus;
        type ExecType;
        type OrderRejectReason;
        type OrderSide;
        type OrderType;
        type OrderDuration;
        type OrderQualifier;
        type PositionSide;
        type PositionEffect;
        type CashPositionChangeReason;
        type AccountState;
    }
 

    #[repr(u32)]
    enum OrderStatus
    {
        OrderStatus_Unknown = 0,
        OrderStatus_New = 1,                   
        OrderStatus_PartiallyFilled = 2,       
        OrderStatus_Filled = 3,                
        OrderStatus_DoneForDay = 4,            
        OrderStatus_Canceled = 5,              
        OrderStatus_PendingCancel = 6,         
        OrderStatus_Stopped = 7,               
        OrderStatus_Rejected = 8,              	
        OrderStatus_Suspended = 9,             
        OrderStatus_PendingNew = 10,           
        OrderStatus_Calculated = 11,           
        OrderStatus_Expired = 12,              
        OrderStatus_AcceptedForBidding = 13,   
        OrderStatus_PendingReplace = 14,       
    }
    #[repr(u32)]
    enum ExecType
    {
        ExecType_Unknown = 0,
        ExecType_New = 1,                       
        ExecType_DoneForDay = 4,                
        ExecType_Canceled = 5,                  
        ExecType_PendingCancel = 6,             
        ExecType_Stopped = 7,                   
        ExecType_Rejected = 8,                  
        ExecType_Suspended = 9,                 
        ExecType_PendingNew = 10,               
        ExecType_Calculated = 11,               
        ExecType_Expired = 12,                  
        ExecType_Restated = 13,                 
        ExecType_PendingReplace = 14,           
        ExecType_Trade = 15,                    
        ExecType_TradeCorrect = 16,             
        ExecType_TradeCancel = 17,              
        ExecType_OrderStatus = 18,              
        ExecType_CancelRejected = 19,           
    }

    #[repr(u32)]
    enum OrderRejectReason
    {
        OrderRejectReason_Unknown = 0,                            
        OrderRejectReason_RiskRuleCheckFailed = 1,                
        OrderRejectReason_NoEnoughCash = 2,                       
        OrderRejectReason_NoEnoughPosition = 3,                   
        OrderRejectReason_IllegalAccountId = 4,                   
        OrderRejectReason_IllegalStrategyId = 5,                  
        OrderRejectReason_IllegalSymbol = 6,                      
        OrderRejectReason_IllegalVolume = 7,                      
        OrderRejectReason_IllegalPrice = 8,                       
        OrderRejectReason_AccountDisabled = 10,                   
        OrderRejectReason_AccountDisconnected = 11,               
        OrderRejectReason_AccountLoggedout = 12,                  
        OrderRejectReason_NotInTradingSession = 13,               
        OrderRejectReason_OrderTypeNotSupported = 14,             
        OrderRejectReason_Throttle = 15,                          
        OrderRejectReason_SymbolSusppended = 16,                  
        OrderRejectReason_Internal = 999,                         

        CancelOrderRejectReason_OrderFinalized = 101,             
        CancelOrderRejectReason_UnknownOrder = 102,               
        CancelOrderRejectReason_BrokerOption = 103,               
        CancelOrderRejectReason_AlreadyInPendingCancel = 104,     
    }

    
    #[repr(u32)]
    enum OrderSide
    {
        OrderSide_Unknown = 0,
        OrderSide_Buy = 1,     
        OrderSide_Sell = 2,     
    }

    
    #[repr(u32)]
    enum OrderType
    {
        OrderType_Unknown = 0,
        OrderType_Limit = 1,     
        OrderType_Market = 2,     
        OrderType_Stop = 3,     
    }

    
    #[repr(u32)]
    enum OrderDuration
    {
        OrderDuration_Unknown = 0,
        OrderDuration_FAK = 1,   
        OrderDuration_FOK = 2,   
        OrderDuration_GFD = 3,   
        OrderDuration_GFS = 4,   
        OrderDuration_GTD = 5,   
        OrderDuration_GTC = 6,   
        OrderDuration_GFA = 7,   
    }

    
    #[repr(u32)]
    enum OrderQualifier
    {
        OrderQualifier_Unknown = 0,
        OrderQualifier_BOC = 1,   
        OrderQualifier_BOP = 2,   
        OrderQualifier_B5TC = 3,   
        OrderQualifier_B5TL = 4,   
    }

    
    #[repr(u32)]
    enum PositionSide
    {
        PositionSide_Unknown = 0,
        PositionSide_Long = 1,    
        PositionSide_Short = 2,    
    }

    
    #[repr(u32)]
    enum PositionEffect
    {
        PositionEffect_Unknown = 0,
        PositionEffect_Open = 1,      
        PositionEffect_Close = 2,      
        PositionEffect_CloseToday = 3,      
        PositionEffect_CloseYesterday = 4,      
    }

    #[repr(u32)]
    enum CashPositionChangeReason
    {
        CashPositionChangeReason_Unknown = 0,
        CashPositionChangeReason_Trade = 1,   
        CashPositionChangeReason_Inout = 2,   
        CashPositionChangeReason_Dividend = 3,   
    }


    #[repr(u32)]
    enum AccountState
    {
        State_UNKNOWN = 0,        
        State_CONNECTING = 1,     
        State_CONNECTED = 2,      
        State_LOGGEDIN = 3,       
        State_DISCONNECTING = 4,  
        State_DISCONNECTED = 5,   
        State_ERROR = 6           
    }
    unsafe extern "C++"{
        include!("gmtrade/include/gmtrade_csdk.h");
        type Order=crate::Order;
        type Position=crate::Position;
    }
    
    #[namespace="gmtrade"]
    unsafe extern "C++"{
        include!("gmtrade/include/wrapper.h");
        type DataArray_AccountStatus;
        type DataArray_Position;
        type Trade;
        
        fn new_trade(toekn:&CxxString)->UniquePtr<Trade>;
        fn start(self:Pin<&mut Trade>)->i32;
        fn stop(self:Pin<&mut Trade>);
        fn login_str(self:Pin<&mut Trade>,account_ids:&CxxString)->i32;
        fn set_endpoint_str(self:Pin<&mut Trade>,serv_addr:&CxxString);
        fn order_volume_str_int(self:Pin<&mut Trade>,symbol:&CxxString, volume:i32, side:i32, order_type:i32, position_effect:i32, price:f64, account:&CxxString)->Order;
        fn get_position_unq(self:Pin<&mut Trade>,account:&CxxString)->UniquePtr<DataArray_Position >;
        fn status(self:Pin<&mut DataArray_Position>)->i32;
        fn data_unq(self:Pin<&mut DataArray_Position>)->UniquePtr<Position>;
        fn at(self:Pin<&mut DataArray_Position>,i:i32)->Pin<&mut Position>;
        fn count(self:Pin<&mut DataArray_Position>)->i32;
    }
    impl UniquePtr<Position> {}

    
}

#[repr(C)]
struct ExecRpt
{
	strategy_id:[c_char;LEN_ID],                   
	account_id:[c_char;LEN_ID],                    
	account_name:[c_char;LEN_NAME],                

	cl_ord_id:[c_char;LEN_ID],                     
	order_id:[c_char;LEN_ID],                      
	exec_id:[c_char;LEN_ID],                       

	symbol:[c_char;LEN_TRADE_SYMBOL],                   

	position_effect:c_int,                      
	side:c_int,                                 
	ord_rej_reason:c_int,                        
	ord_rej_reason_detail:[c_char;LEN_INFO],       
	exec_type:c_int,                            

	price:c_double,                                 
	volume:c_longlong,                                	amount:c_double,                                
    commission:c_double,                            
    cost:c_double,                                  
    created_at:c_longlong,                            
}
#[repr(C)]
struct Cash
{
	account_id:[c_char;LEN_ID],                         
	account_name:[c_char;LEN_NAME],                    

	currency:c_int,                                   

	nav:c_double,                                         
	pnl:c_double,                                         
	fpnl:c_double,                                        
	frozen:c_double,                                      
	order_frozen:c_double,                                
	available:c_double,                                   
													 
													 
													 
	balance:c_double,                                     

	cum_inout:c_double,                                   
	cum_trade:c_double,                                   
	cum_pnl:c_double,                                     
	cum_commission:c_double,                              

	last_trade:c_double,                                  
	last_pnl:c_double,                                    
	last_commission:c_double,                             
	last_inout:c_double,                                  
	change_reason:c_int,                               
	change_event_id:[c_char;LEN_ID],                     

	created_at:c_longlong,                                  
	updated_at:c_longlong,                                  

}
#[repr(C)]
struct Position
{
	account_id:[c_char;LEN_ID],               
	account_name:[c_char;LEN_NAME],           

	symbol:[c_char;LEN_TRADE_SYMBOL],               
	side:c_int,                             
	volume:c_longlong,                           
	volume_today:c_longlong,                     
	vwap:c_double,                             
	amount:c_double,                           

	price:c_double,                            
	fpnl:c_double,                             
	cost:c_double,                             
	order_frozen:c_longlong,                     
	order_frozen_today:c_longlong,               
	available:c_longlong,                        
	available_today:c_longlong,                  
	available_now:c_longlong,                    

	last_price:c_double,                       
	last_volume:c_longlong,                      
	last_inout:c_longlong,                       
	change_reason:c_int,                    
	change_event_id:[c_char;LEN_ID],          

	has_dividend:c_int,                     
	created_at:c_longlong,                       
	updated_at:c_longlong,                       

}
unsafe impl ExternType for Position {
    type Id = type_id!("Position");
    type Kind = cxx::kind::Trivial;
}



#[repr(C)]
struct Account
{
	account_id:[c_char;LEN_ID],            
	account_name:[c_char;LEN_NAME],        
	title:[c_char;LEN_NAME],               
	intro:[c_char;LEN_INFO],               
	comment:[c_char;LEN_INFO],             
}

#[repr(C)]
struct AccountStatus
{
	account_id:[c_char;LEN_ID],            
	account_name:[c_char;LEN_NAME],        
	state:c_int,                         
	error_code:c_int,                    
	error_msg:[c_char;LEN_INFO],           
}


#[link(name="gmtrade")]
extern "C"{
    fn gmi_set_event_callback(cb:EventCallback);
    fn gmi_set_event_callback_pb(cb:EventCallback);
    fn gmi_set_token(token:*const u8)->c_int;
    fn gmi_set_serv_addr(addr:*const u8);

    //运行策略
    fn gmi_run()->c_int;
    //开始运行策略
    fn gmi_start()->c_int;
    //实盘模式初始化
    fn gmi_init()->c_int;
    //运行策略
    fn gmi_poll()->c_int;
    //停止策略
    fn gmi_stop()->c_int;
    //获取c-sdk版本号
    fn gmi_get_c_version()->*const u8;
    //根据错误码获取错误信息
    fn gmi_strerror(errorno:c_int)->*const u8;
    //获取扩展错误信息
    fn gmi_get_ext_errormsg()->*const u8;
    fn gmi_gbk2utf(gbk:*const u8)->*mut u8;
    fn gmi_utf2gbk(utf8:*const u8)->*mut u8;
    //设置sdk信息
    fn gmi_set_version(sdk_version:*const u8, sdk_lang:*const u8, sdk_arch:*const u8, sdk_os:*const u8);//后面两个默认是NULL,默认是不鼓励的,需要自己注意
    //定时器
    fn gmi_set_timer(interval:c_int);
    //交易类 API ////////////////////////////////////////////////////
    //设置默认账号
    fn gmi_login(account_ids:*const u8)->c_int;
    //下单委托
    fn gmi_place_order(orders:*mut Order, order_count:c_int,is_combined:c_int, res:*mut *mut Order, count:*mut c_int)->c_int;

    //下单委托 req = core.api.Orders, res = core.api.Orders
    fn gmi_place_order_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //平所有仓位
    fn gmi_close_all_positions(account_ids:*const u8,res:*mut *mut Order, count:*mut c_int)->c_int;

    //平所有仓位 req = trade.api.CloseAllPositionsReq, res = core.api.Orders
    fn gmi_close_all_positions_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //撤单委托 
    fn gmi_cancel_orders(orders:*mut Order,count:c_int)->c_int;

    //撤单委托 req = core.api.Orders
    fn gmi_cancel_orders_pb(req:*mut c_void, req_len:c_int)->c_int;

    //撤销所有委托
    fn gmi_cancel_all_orders(account_ids:*const u8)->c_int;

    //撤销所有委托 req = trade.api.CancelAllOrdersReq
    fn gmi_cancel_all_orders_pb(req:*mut c_void, req_len:c_int)->c_int;

    //查询委托
    fn gmi_get_orders(account:*const u8, symbols:*const u8, cl_ord_ids:*const u8, res:*mut *mut Order, count:*mut c_int)->c_int;

    //查询委托 req = trade.api.GetOrdersReq, res = core.api.Orders
    fn gmi_get_orders_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //查询未结委托
    fn gmi_get_unfinished_orders(account:*const u8, res:*mut *mut Order, count:*mut c_int)->c_int;

    //查询未结委托 req = trade.api.GetUnfinishedOrdersReq, res = core.api.Orders
    fn gmi_get_unfinished_orders_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //查询资金
    fn gmi_get_cash(account:*const u8, cash:*mut *mut Cash, count:*mut c_int)->c_int;

    //查询资金  req = trade.api.GetCashReq, res = core.api.Cashes
    fn gmi_get_cash_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //查询持仓
    fn gmi_get_positions(account:*const u8, symbol:*const u8,  side:c_int, res:*mut *mut Position, count:*mut c_int)->c_int;

    //查询持仓 req = trade.api.GetPositionsReq, res = core.api.Positions
    fn gmi_get_positions_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //查询成交
    fn gmi_get_execution_reports(account:*const u8, cl_ord_id:*const u8, exec_type:c_int, res:*mut *mut ExecRpt, count:*mut c_int)->c_int;

    //查询成交 req = trade.api.GetExecrptsReq, res = core.api.ExecRpts
    fn gmi_get_execution_reports_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

    //获取交易账户状态
    fn gmi_get_account_status(accounts:*const u8, res:*mut *mut AccountStatus, count:*mut c_int)->c_int;

    //获取交易账户状态 req = tradegw.api.GetAccountStatusesReq, res = core.api.AccountStatuses
    fn gmi_get_account_status_pb(req:*mut c_void, req_len:c_int, res:*mut *mut c_void, res_len:*mut c_int)->c_int;

}






fn main() {
    let_cxx_string!(token="0929b656ef715fb92b22dcff58ff4263ff840778");
    let_cxx_string!(endpoint="api.myquant.cn:9000");
    let_cxx_string!(account_id="5c81874e-2021-11eb-88c5-00163e0a4100");
    let_cxx_string!(position="");
    let mut mt =ffi::new_trade(&token);
    mt.pin_mut().set_endpoint_str(&endpoint);
    let a=mt.pin_mut().login_str(&account_id);
    let mut ps=mt.pin_mut().get_position_unq(&position);
    let status=ps.pin_mut().status();
    let pos=ps.pin_mut().data_unq();
    let count=ps.pin_mut().count();

    println!("count:{}",count);
    if status==0{
        
    }
    println!("success:{}",a);
    println!("status:{}",status);

}
