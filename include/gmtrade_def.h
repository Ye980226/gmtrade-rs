#include<memory>

#ifndef GMTRADE_DEF_H
#define GMTRADE_DEF_H


const unsigned int LEN_TRADE_SYMBOL = 32;
const unsigned int LEN_ID = 64;
const unsigned int LEN_NAME = 64;
const unsigned int LEN_INFO = 128;

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
};

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
};

 
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
};

 
enum OrderSide
{
	OrderSide_Unknown = 0,
	OrderSide_Buy = 1,     
	OrderSide_Sell = 2,     
};

 
enum OrderType
{
	OrderType_Unknown = 0,
	OrderType_Limit = 1,     
	OrderType_Market = 2,     
	OrderType_Stop = 3,     
};

 
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
};

 
enum OrderQualifier
{
	OrderQualifier_Unknown = 0,
	OrderQualifier_BOC = 1,   
	OrderQualifier_BOP = 2,   
	OrderQualifier_B5TC = 3,   
	OrderQualifier_B5TL = 4,   
};


 
enum PositionSide
{
	PositionSide_Unknown = 0,
	PositionSide_Long = 1,    
	PositionSide_Short = 2,    
};

 
enum PositionEffect
{
	PositionEffect_Unknown = 0,
	PositionEffect_Open = 1,      
	PositionEffect_Close = 2,      
	PositionEffect_CloseToday = 3,      
	PositionEffect_CloseYesterday = 4,      
};

 
enum CashPositionChangeReason
{
	CashPositionChangeReason_Unknown = 0,
	CashPositionChangeReason_Trade = 1,   
	CashPositionChangeReason_Inout = 2,   
	CashPositionChangeReason_Dividend = 3,   
};

enum AccountState
{
	State_UNKNOWN = 0,        
	State_CONNECTING = 1,     
	State_CONNECTED = 2,      
	State_LOGGEDIN = 3,       
	State_DISCONNECTING = 4,  
	State_DISCONNECTED = 5,   
	State_ERROR = 6           
};


typedef char Symbol[LEN_TRADE_SYMBOL];

struct Order
{
	char         strategy_id[LEN_ID];                      
	char         account_id[LEN_ID];                       
	char         account_name[LEN_NAME];                   

	char         cl_ord_id[LEN_ID];                        
	char         order_id[LEN_ID];                         
	char         ex_ord_id[LEN_ID];                        

	char         symbol[LEN_TRADE_SYMBOL];                       
	int          side;                                     
	int          position_effect;                          
	int          position_side;                            

	int          order_type;                               
	int          order_duration;                           
	int          order_qualifier;                          
	int          order_src;                                

	int          status;                                   
	int          ord_rej_reason;                           
	char         ord_rej_reason_detail[LEN_INFO];          

	double       price;                                    
	double       stop_price;                               

	int          order_style;                              
	long long    volume;                                   
	double       value;                                    
	double       percent;                                  
	long long    target_volume;                            
	double       target_value;                             
	double       target_percent;                           

	long long    filled_volume;                            
	double       filled_vwap;                              
	double       filled_amount;                            
	double       filled_commission;                        

	long long    created_at;                               
	long long    updated_at;                               
};

struct ExecRpt
{
	char               strategy_id[LEN_ID];                   
	char               account_id[LEN_ID];                    
	char               account_name[LEN_NAME];                

	char               cl_ord_id[LEN_ID];                     
	char               order_id[LEN_ID];                      
	char               exec_id[LEN_ID];                       

	char               symbol[LEN_TRADE_SYMBOL];                    

	int                position_effect;                       
	int                side;                                  
	int                ord_rej_reason;                        
	char               ord_rej_reason_detail[LEN_INFO];       
	int                exec_type;                             

	double             price;                                 
	long long          volume;                                
	double             amount;                                
	double             commission;                            
	double             cost;                                  
	long long          created_at;                            

};

struct Cash
{
	char          account_id[LEN_ID];                         
	char          account_name[LEN_NAME];                     

	int           currency;                                   

	double        nav;                                         
	double        pnl;                                         
	double        fpnl;                                        
	double        frozen;                                      
	double        order_frozen;                                
	double        available;                                   
																 
																 
																 
	double        balance;                                     

	double        cum_inout;                                   
	double        cum_trade;                                   
	double        cum_pnl;                                     
	double        cum_commission;                              

	double        last_trade;                                  
	double        last_pnl;                                    
	double        last_commission;                             
	double        last_inout;                                  
	int           change_reason;                               
	char          change_event_id[LEN_ID];                     

	long long     created_at;                                  
	long long     updated_at;                                  

};

struct Position
{
	char                 account_id[LEN_ID];               
	char                 account_name[LEN_NAME];           

	char                 symbol[LEN_TRADE_SYMBOL];               
	int                  side;                             
	long long            volume;                           
	long long            volume_today;                     
	double               vwap;                             
	double               amount;                           

	double               price;                            
	double               fpnl;                             
	double               cost;                             
	long long            order_frozen;                     
	long long            order_frozen_today;               
	long long            available;                        
	long long            available_today;                  
	long long            available_now;                    

	double               last_price;                       
	long long            last_volume;                      
	long long            last_inout;                       
	int                  change_reason;                    
	char                 change_event_id[LEN_ID];          

	int                  has_dividend;                     
	long long            created_at;                       
	long long            updated_at;                       

};

struct Account
{
	char            account_id[LEN_ID];            
	char            account_name[LEN_NAME];        
	char            title[LEN_NAME];               
	char            intro[LEN_INFO];               
	char            comment[LEN_INFO];             
};

struct AccountStatus
{
	char            account_id[LEN_ID];            
	char            account_name[LEN_NAME];        
	int             state;                         
	int             error_code;                    
	char            error_msg[LEN_INFO];           
};

namespace gmtrade
{
	template <typename T>
	class DataArray
	{
	public:
		 
		virtual int status() = 0;
 
		virtual T* data() = 0;

		std::unique_ptr<T> data_unq();
		 
		virtual int count() = 0;

		
		virtual T& at(int i) = 0;

		 
		virtual void release() = 0;
	};
}  
#endif
