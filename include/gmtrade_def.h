#ifndef GMTRADE_DEF_H
#define GMTRADE_DEF_H

const unsigned int LEN_TRADE_SYMBOL = 32;
const unsigned int LEN_ID = 64;
const unsigned int LEN_NAME = 64;
const unsigned int LEN_INFO = 128;

enum OrderStatus
{
	OrderStatus_Unknown = 0,
	OrderStatus_New = 1,                   //�ѱ�
	OrderStatus_PartiallyFilled = 2,       //����
	OrderStatus_Filled = 3,                //�ѳ�
	OrderStatus_DoneForDay = 4,            //
	OrderStatus_Canceled = 5,              //�ѳ�
	OrderStatus_PendingCancel = 6,         //����
	OrderStatus_Stopped = 7,               //
	OrderStatus_Rejected = 8,              //�Ѿܾ�
	OrderStatus_Suspended = 9,             //����
	OrderStatus_PendingNew = 10,           //����
	OrderStatus_Calculated = 11,           //
	OrderStatus_Expired = 12,              //�ѹ���
	OrderStatus_AcceptedForBidding = 13,   //
	OrderStatus_PendingReplace = 14,       //
};

//ִ�лر�����
enum ExecType
{
	ExecType_Unknown = 0,
	ExecType_New = 1,                      //�ѱ�
	ExecType_DoneForDay = 4,               //
	ExecType_Canceled = 5,                 //�ѳ���
	ExecType_PendingCancel = 6,            //������
	ExecType_Stopped = 7,                  //
	ExecType_Rejected = 8,                 //�Ѿܾ�
	ExecType_Suspended = 9,                //����
	ExecType_PendingNew = 10,              //����
	ExecType_Calculated = 11,              //
	ExecType_Expired = 12,                 //����
	ExecType_Restated = 13,                //
	ExecType_PendingReplace = 14,          //
	ExecType_Trade = 15,                   //�ɽ�
	ExecType_TradeCorrect = 16,            //
	ExecType_TradeCancel = 17,             //
	ExecType_OrderStatus = 18,             //ί��״̬
	ExecType_CancelRejected = 19,          //�������ܾ�
};

//ί�оܾ�ԭ��
enum OrderRejectReason
{
	OrderRejectReason_Unknown = 0,                           //δ֪ԭ��
	OrderRejectReason_RiskRuleCheckFailed = 1,               //�����Ϸ�ع��� 
	OrderRejectReason_NoEnoughCash = 2,                      //�ʽ���
	OrderRejectReason_NoEnoughPosition = 3,                  //��λ����
	OrderRejectReason_IllegalAccountId = 4,                  //�Ƿ��˻�ID
	OrderRejectReason_IllegalStrategyId = 5,                 //�Ƿ�����ID
	OrderRejectReason_IllegalSymbol = 6,                     //�Ƿ����״���
	OrderRejectReason_IllegalVolume = 7,                     //�Ƿ�ί����
	OrderRejectReason_IllegalPrice = 8,                      //�Ƿ�ί�м�
	OrderRejectReason_AccountDisabled = 10,                  //�����˺ű���ֹ����
	OrderRejectReason_AccountDisconnected = 11,              //�����˺�δ����
	OrderRejectReason_AccountLoggedout = 12,                 //�����˺�δ��¼
	OrderRejectReason_NotInTradingSession = 13,              //�ǽ���ʱ��
	OrderRejectReason_OrderTypeNotSupported = 14,            //ί�����Ͳ�֧��
	OrderRejectReason_Throttle = 15,                         //��������
	OrderRejectReason_SymbolSusppended = 16,                 //���״���ͣ��
	OrderRejectReason_Internal = 999,                        //�ڲ�����

	CancelOrderRejectReason_OrderFinalized = 101,            //ί�������
	CancelOrderRejectReason_UnknownOrder = 102,              //δ֪ί��
	CancelOrderRejectReason_BrokerOption = 103,              //��̨����
	CancelOrderRejectReason_AlreadyInPendingCancel = 104,    //ί�г�����
};

//ί�з���
enum OrderSide
{
	OrderSide_Unknown = 0,
	OrderSide_Buy = 1,    //����
	OrderSide_Sell = 2,    //����
};

//ί������
enum OrderType
{
	OrderType_Unknown = 0,
	OrderType_Limit = 1,    //�޼�ί��
	OrderType_Market = 2,    //�м�ί��
	OrderType_Stop = 3,    //ֹ��ֹӯί��
};

//ί��ʱ������
enum OrderDuration
{
	OrderDuration_Unknown = 0,
	OrderDuration_FAK = 1,  //��ʱ�ɽ�ʣ�೷��(fill and kill)
	OrderDuration_FOK = 2,  //��ʱȫ��ɽ�����(fill or kill)
	OrderDuration_GFD = 3,  //������Ч(good for day)
	OrderDuration_GFS = 4,  //������Ч(good for section)
	OrderDuration_GTD = 5,  //ָ������ǰ��Ч(goodl till date)
	OrderDuration_GTC = 6,  //����ǰ��Ч(good till cancel)
	OrderDuration_GFA = 7,  //���Ͼ���ǰ��Ч(good for auction)
};

//ί�гɽ�����
enum OrderQualifier
{
	OrderQualifier_Unknown = 0,
	OrderQualifier_BOC = 1,  //�Է����ż۸�(best of counterparty)
	OrderQualifier_BOP = 2,  //�������ż۸�(best of party)
	OrderQualifier_B5TC = 3,  //�����嵵ʣ�೷��(best 5 then cancel)
	OrderQualifier_B5TL = 4,  //�����嵵ʣ��ת�޼�(best 5 then limit)
};


//�ֲַ���
enum PositionSide
{
	PositionSide_Unknown = 0,
	PositionSide_Long = 1,   //�෽��
	PositionSide_Short = 2,   //�շ���
};

//��ƽ��־
enum PositionEffect
{
	PositionEffect_Unknown = 0,
	PositionEffect_Open = 1,     //����
	PositionEffect_Close = 2,     //ƽ��,��������ȡ���ڶ�Ӧ�Ľ�����
	PositionEffect_CloseToday = 3,     //ƽ���
	PositionEffect_CloseYesterday = 4,     //ƽ���
};

//�ʽ�ֱֲ��ԭ��
enum CashPositionChangeReason
{
	CashPositionChangeReason_Unknown = 0,
	CashPositionChangeReason_Trade = 1,  //����
	CashPositionChangeReason_Inout = 2,  //�����/����ֲ�
	CashPositionChangeReason_Dividend = 3,  //�ֺ��͹�
};

enum AccountState
{
	State_UNKNOWN = 0,       //δ֪
	State_CONNECTING = 1,    //������
	State_CONNECTED = 2,     //������
	State_LOGGEDIN = 3,      //�ѵ�¼
	State_DISCONNECTING = 4, //�Ͽ���
	State_DISCONNECTED = 5,  //�ѶϿ�
	State_ERROR = 6          //����
};


typedef char Symbol[LEN_TRADE_SYMBOL];

struct Order
{
	char         strategy_id[LEN_ID];                     //����ID                                      
	char         account_id[LEN_ID];                      //�˺�ID                                      
	char         account_name[LEN_NAME];                  //�˻���¼��                                  

	char         cl_ord_id[LEN_ID];                       //ί�пͻ���ID                                
	char         order_id[LEN_ID];                        //ί�й�̨ID                                  
	char         ex_ord_id[LEN_ID];                       //ί�н�����ID                                

	char         symbol[LEN_TRADE_SYMBOL];                      //symbol                                      
	int          side;                                    //��������ȡֵ�ο�enum OrderSide            
	int          position_effect;                         //��ƽ��־��ȡֵ�ο�enum PositionEffect       
	int          position_side;                           //�ֲַ���ȡֵ�ο�enum PositionSide         

	int          order_type;                              //ί�����ͣ�ȡֵ�ο�enum OrderType            
	int          order_duration;                          //ί��ʱ�����ԣ�ȡֵ�ο�enum OrderDuration    
	int          order_qualifier;                         //ί�гɽ����ԣ�ȡֵ�ο�enum OrderQualifier   
	int          order_src;                               //ί����Դ��ȡֵ�ο�enum OrderSrc             

	int          status;                                  //ί��״̬��ȡֵ�ο�enum OrderStatus          
	int          ord_rej_reason;                          //ί�оܾ�ԭ��ȡֵ�ο�enum OrderRejectReason
	char         ord_rej_reason_detail[LEN_INFO];         //ί�оܾ�ԭ������                            

	double       price;                                   //ί�м۸�                                    
	double       stop_price;                              //ί��ֹ��/ֹӯ�����۸�                       

	int          order_style;                             //ί�з��ȡֵ�ο� enum OrderStyle          
	long long    volume;                                  //ί����                                      
	double       value;                                   //ί�ж�                                      
	double       percent;                                 //ί�аٷֱ�                                  
	long long    target_volume;                           //ί��Ŀ����                                  
	double       target_value;                            //ί��Ŀ���                                  
	double       target_percent;                          //ί��Ŀ��ٷֱ�                              

	long long    filled_volume;                           //�ѳ���                                      
	double       filled_vwap;                             //�ѳɾ���                                    
	double       filled_amount;                           //�ѳɽ��                                    
	double       filled_commission;                       //�ѳ�������                                  

	long long    created_at;                              //ί�д���ʱ��                                
	long long    updated_at;                              //ί�и���ʱ��  
};

struct ExecRpt
{
	char               strategy_id[LEN_ID];                  //����ID                                                                                                        
	char               account_id[LEN_ID];                   //�˺�ID                                                       
	char               account_name[LEN_NAME];               //�˻���¼��                                                                                                    

	char               cl_ord_id[LEN_ID];                    //ί�пͻ���ID                                                                                                  
	char               order_id[LEN_ID];                     //ί�й�̨ID                                                                                                    
	char               exec_id[LEN_ID];                      //ί�лر�ID                                                                                                    

	char               symbol[LEN_TRADE_SYMBOL];                   //symbol                                                                                                        

	int                position_effect;                      //��ƽ��־��ȡֵ�ο�enum PositionEffect                                                                         
	int                side;                                 //��������ȡֵ�ο�enum OrderSide                                                                              
	int                ord_rej_reason;                       //ί�оܾ�ԭ��ȡֵ�ο�enum OrderRejectReason                                                                  
	char               ord_rej_reason_detail[LEN_INFO];      //ί�оܾ�ԭ������                                                                                              
	int                exec_type;                            //ִ�лر�����, ȡֵ�ο�enum ExecType                                                                           

	double             price;                                //ί�гɽ��۸�                                                                                                  
	long long          volume;                               //ί�гɽ���                                                                                                    
	double             amount;                               //ί�гɽ����                                                                                                  
	double             commission;                           //ί�гɽ�������                                                                                                
	double             cost;                                 //ί�гɽ��ɱ����  
	long long          created_at;                           //�ر�����ʱ��

};

struct Cash
{
	char          account_id[LEN_ID];                        //�˺�ID               
	char          account_name[LEN_NAME];                    //�˻���¼��                                                                   

	int           currency;                                  //����                                                                         

	double        nav;                                        //��ֵ(cum_inout + cum_pnl + fpnl - cum_commission)                            
	double        pnl;                                        //������(nav-cum_inout)                                                        
	double        fpnl;                                       //����ӯ��(sum(each position fpnl))                                            
	double        frozen;                                     //�ֲ�ռ���ʽ�                                                                 
	double        order_frozen;                               //�ҵ������ʽ�                                                                 
	double        available;                                  //�����ʽ�                                                                     
																//no  leverage:  available=(cum_inout + cum_pnl - cum_commission - frozen - order_frozen)        
																//has leverage:  fpnl     =(fpnl>0 ? fpnl : (frozen < |fpnl|) ? (frozen-|fpnl|) : 0)             
																//               available=(cum_inout + cum_pnl - cum_commission - frozen - order_frozen + fpnl) 
	double        balance;                                    //�ʽ����                                                                     

	double        cum_inout;                                  //�ۼƳ����                                                                   
	double        cum_trade;                                  //�ۼƽ��׶�                                                                   
	double        cum_pnl;                                    //�ۼ�ƽ������(û�۳�������)                                                   
	double        cum_commission;                             //�ۼ�������                                                                   

	double        last_trade;                                 //��һ�ν��׶�                                                                 
	double        last_pnl;                                   //��һ������                                                                   
	double        last_commission;                            //��һ��������                                                                 
	double        last_inout;                                 //��һ�γ����                                                                 
	int           change_reason;                              //�ʽ���ԭ��ȡֵ�ο�enum CashPositionChangeReason                          
	char          change_event_id[LEN_ID];                    //�����ʽ����¼���ID     

	long long     created_at;                                 //�ʽ��ʼʱ��
	long long     updated_at;                                 //�ʽ���ʱ��

};

struct Position
{
	char                 account_id[LEN_ID];              //�˺�ID                                       
	char                 account_name[LEN_NAME];          //�˻���¼��                                                                                       

	char                 symbol[LEN_TRADE_SYMBOL];              //symbol                                       
	int                  side;                            //�ֲַ���ȡֵ�ο�enum PositionSide          
	long long            volume;                          //�ֲܳ���; ��ֲ���(volume-volume_today)                                                          
	long long            volume_today;                    //���ճֲ���                                                                                       
	double               vwap;                            //�ֲ־���                                                                                         
	double               amount;                          //�ֲֶ�(volume*vwap*multiplier)                                                                   

	double               price;                           //��ǰ����۸�                                                                                     
	double               fpnl;                            //�ֲָ���ӯ��((price-vwap)*volume*multiplier)                                                     
	double               cost;                            //�ֲֳɱ�(vwap*volume*multiplier*margin_ratio)                                                    
	long long            order_frozen;                    //�ҵ������λ                                                                                     
	long long            order_frozen_today;              //�ҵ������ֲ�λ                                                                                 
	long long            available;                       //�����ܲ�λ(volume-order_frozen); �������λ(available-available_today)                           
	long long            available_today;                 //���ý��λ(volume_today-order_frozen_today)
	long long            available_now;                   //��ǰ��ƽ��λ                                                   

	double               last_price;                      //��һ�γɽ���                                                                                     
	long long            last_volume;                     //��һ�γɽ���                                                                                     
	long long            last_inout;                      //��һ�γ���ֲ���                                                                                 
	int                  change_reason;                   //��λ���ԭ��ȡֵ�ο�enum CashPositionChangeReason                                              
	char                 change_event_id[LEN_ID];         //�����ʽ����¼���ID                                                                             

	int                  has_dividend;                    //�ֲ������зֺ�����   
	long long            created_at;                      //����ʱ��
	long long            updated_at;                      //��λ���ʱ��

};

struct Account
{
	char            account_id[LEN_ID];           //�˺�ID
	char            account_name[LEN_NAME];       //�˻���¼��
	char            title[LEN_NAME];              //�˺�����
	char            intro[LEN_INFO];              //�˺�����
	char            comment[LEN_INFO];            //�˺ű�ע
};

struct AccountStatus
{
	char            account_id[LEN_ID];           //�˺�ID
	char            account_name[LEN_NAME];       //�˻���¼��
	int             state;                        //�˻�״̬
	int             error_code;                   //������
	char            error_msg[LEN_INFO];          //������Ϣ
};

namespace gmtrade
{
	//�������
	template <typename T>
	class DataArray
	{
	public:
		//��ȡapi���ý��, 0: �ɹ��� ��0: ������
		virtual int status() = 0;

		//���ؽṹ�����ָ��
		virtual T* data() = 0;

		//�������ݵĳ���
		virtual int count() = 0;

		//�����±�Ϊi�Ľṹ���ã���0��ʼ
		virtual T& at(int i) = 0;

		//�ͷ����ݼ���
		virtual void release() = 0;
	};

} //namespace gmtrade

#endif
