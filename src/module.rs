use std::boxed::Box;
use cxx::UniquePtr;
use cxx::{type_id, ExternType};
use std::os::raw::{c_void,c_char,c_int,c_double,c_longlong};
use std::ptr::{null_mut,null};
use cxx::let_cxx_string;
//gmtrade_csdk.h
type EventCallback=extern fn(msg_type:*const u8,data:*const c_void,data_len:c_int);
const LEN_TRADE_SYMBOL:usize=32;
const LEN_ID:usize=64;
const LEN_NAME:usize=64;
const LEN_INFO:usize=128;
const NULL:*const c_void=0 as *const c_void;

#[repr(C)]
pub struct Order
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


#[cxx::bridge]
mod strategy{
    extern "C++"{
        include!("gmtrade/include/gmtrade_csdk.h");
        type Order=crate::Order;
	}
    extern "Rust"{
    	fn on_order(order:Box<Order>);
	}

}
pub fn on_order(order:Box<strategy::Order>){
	println!("I am a student.");
}

