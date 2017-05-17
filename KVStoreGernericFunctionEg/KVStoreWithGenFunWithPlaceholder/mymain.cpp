#include "myheader.h"

void fun(string data){
 cout<<"Fun:"<<data<<endl;
}

class ABC{
 private:
  int id;
 public:
  ABC(int i){
   id=i;
  }
  void fun(int y,string x){
   cout<<"id:"<<id<<" x:"<<x<<" y:"<<y<<endl;
  }
};

int main(){
 TKVStore<string,string> ks;
 ks.async_get("KEY1",fun);
 
 ABC a(111);
 ks.async_get("KEY2",&ABC::fun,&a,222);
}
