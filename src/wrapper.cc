#include "gmtrade/src/main.rs.h"
// #include "gmtrade/include/wrapper.h"//redeclaration error 
using namespace gmtrade;
namespace gmtrade{
    std::unique_ptr<Trade> new_trade(const std::string &token)
    {
        std::unique_ptr<Trade> ptr(new Trade(token.c_str()));
        return ptr;
    }
    void Trade::set_endpoint_str(const std::string & serv_addr){
    this->set_endpoint(serv_addr.c_str());
    }
    int Trade::login_str(const std::string &account_ids){
    return this->login(account_ids.c_str());
    }
    std::unique_ptr<DataArray_Position> Trade::get_position_unq(const std::string & account){
    const char *account_char=NULL;
    if (account!="")
        const char * account_char =account.c_str();
    std::unique_ptr<DataArray_Position>  p (this->get_position(account_char));
    return p; 
    }
}
// on_order(rust::Box<Order>::new(Order()));