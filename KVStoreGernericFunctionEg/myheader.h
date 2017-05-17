#include<iostream>
#include<vector>
#include "myimpl.h"

using namespace std;

template<typename keytype,typename valtype>
class TKVStore{
 public:
 template<typename Fn, typename... Args>
 void async_get(keytype const& key, Fn&& f,Args&&... args);
};

template<typename keytype,typename valtype>
template<typename Fn, typename... Args>
 void TKVStore<keytype,valtype>::async_get(keytype const& key, Fn&& f,Args&&... args){
  std::function<void()> fun = std::bind(f,args...);
  auto lambda_fn = [](string data,std::function<void()> fun){
    cout<<"Data:"<<data<<endl;
    fun();
  };
  KVHelper kh;
  //key is already in string assume
  // else use boost seralization
  kh.async_get(key,lambda_fn,fun);
  cout<<"Called with key"<<key<<endl;
 }
