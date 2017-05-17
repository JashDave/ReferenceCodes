#include "myimpl.h"

void KVHelper::async_get(string key,void (*lfn)(string data,void* fun), void* fun){
 cout<<"getiing key from ds:"<<key<<endl;
 string data = "got somting from server";
 lfn(data,fun);
}

