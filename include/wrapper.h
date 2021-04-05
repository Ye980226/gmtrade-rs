#pragma once
#include "gmtrade/include/gmtrade.h"
#include <string>


using namespace gmtrade;

namespace gmtrade{
  typedef  DataArray<AccountStatus> DataArray_AccountStatus;
  typedef  DataArray<Position> DataArray_Position;
  std::unique_ptr<Trade> new_trade(const std::string &token);
  // void Trade::set_endpoint_str(const std::string & serv_addr);
  // std::unique_ptr<DataArray_Position> Trade::get_position_unq(const std::string & account);
  // int Trade::login_str(const std::string &account_ids);
  
  template<typename T>
  std::unique_ptr<T> DataArray<T>::data_unq()
  {
    std::unique_ptr<T> p (this->data());
    return p; 
  }
  template<typename T>
  T& DataArray<T>::at(int i);
  template <typename T>
  int DataArray<T>::count();
}

// std::unique_ptr<DataArray_AccountStatus> new_data_array_account_status (){
//     return std::make_unique<DataArray_AccountStatus>();
// }//就可以直接用普通指针创建智能指针，只需要稍微封装一下就ojbk，cool，模板类不能用，用typedef把需要的重新定义一下，char *全部转成std::string

// class DataArray_AccountStatus{
//     public:
//         std::unique_ptr<DataArray<AccountStatus>> produce_dr_acst(){
//             std::make_unique<DataArray<AccountStatus>()>;
//         }
// };