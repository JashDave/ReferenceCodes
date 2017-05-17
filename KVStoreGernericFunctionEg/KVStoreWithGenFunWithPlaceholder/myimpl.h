#include <iostream>
#include <functional>
using namespace std;

class KVHelper{
 public:
 void async_get(string key,void (*lfn)(string data,void* fun), void* fun);
};
