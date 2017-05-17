#include "myimpl.h"

void KVHelper::async_get(string key,void (*lfn)(string data,std::function<void()> fun), std::function<void()> fun){
 cout<<"getiing key from ds:"<<key<<endl;
 string data = "got somting from server";
 lfn(data,fun);
}

