#[cxx::bridge]
mod ffi{
    extern "C++"{
        include!("demo/include/gmtrade_def.h");
        type OrderStatus;
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

}
fn main() {
    let c=ffi::OrderStatus::OrderStatus_Unknown;
    if let ffi::OrderStatus::OrderStatus_Unknown=c{
        println!("success ");
    };
    println!("Hello, world!");
}
