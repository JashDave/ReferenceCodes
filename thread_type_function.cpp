#include<iostream>
#include<functional>

using namespace std;


// Generic function as input
template <typename Fn, typename... Args>
void generic_fun(Fn&& f,Args&&... args){
    auto x = bind(f,args...);
    x();
}

void sumup(int a, int b){
  cout<<a+b<<endl;
}

class ABC{
  private:
    int a,b;

  public:
    ABC(int x, int y){
      a=x;
      b=y;
    }
    void sumup(int c){
      cout<<a+b+c<<endl;
    }
};

int main(){
    generic_fun(sumup,10,20);
    ABC a(100,20);
    generic_fun(&ABC::sumup,&a,3);
    return 0;
}
