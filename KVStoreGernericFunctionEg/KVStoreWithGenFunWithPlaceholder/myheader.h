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
  std::function<void(string)> fun = std::bind(f,args...,std::placeholders::_1);
  auto lambda_fn = [](string data,void *fn){
    cout<<"Data:"<<data<<endl;
    std::function<void(string)> *fun = (std::function<void(string)> *) fn;
    (*fun)(data);
  };
  KVHelper kh;
  //key is already in string assume
  // else use boost seralization
  kh.async_get(key,lambda_fn,(void*)&fun);
  cout<<"Called with key"<<key<<endl;
 }
