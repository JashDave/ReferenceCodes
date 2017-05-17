#include "myheader.h"

void fun(){
 cout<<"Fun"<<endl;
}

class ABC{
 private:
  int id;
 public:
  ABC(int i){
   id=i;
  }
  void fun(string x,int y){
   cout<<"id:"<<id<<" x:"<<x<<" y:"<<y<<endl;
  }
};

int main(){
 TKVStore<string,string> ks;
 ks.async_get("KEY1",fun);
 
 ABC a(111);
 ks.async_get("KEY2",&ABC::fun,&a,"Xval",222);
}
