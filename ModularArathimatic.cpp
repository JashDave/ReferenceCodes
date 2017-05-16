#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class ModularFactorial{
private:
  vector<ull> facttable;
  ull mod;
public:
  ModularFactorial(ull size,ull m){
    facttable.resize(size,0);
    facttable[0]=1;
    mod = m;
  }
  ull fact(int x){
    if(facttable[x]!=0) return facttable[x];
    facttable[x] = (fact(x-1)*x) % mod;
    return facttable[x];
  }
};

ull modularPower(ull n,ull p, ull m){
  ull ret = 1;
  n = n % m;
  while (p > 0)
  {
    if (p & 1) {
      ret = (ret*n) % m;
    }
    p = p>>1;
    n = (n*n) % m;
  }
  return ret;
}


// Lucas' Theorem.
// Eulars law for modular division
class ModularCombination{
private:
  ModularFactorial *f;
  ull mod;
  ull n;
  bool del;
public:
  ModularCombination(int n_,ull m, ModularFactorial *f_=NULL){
    n = n_;
    mod = m;
    if(f_ == NULL){
      f = new ModularFactorial(n,mod);
      del = true;
    } else {
      f = f_;
      del = false;
    }
  }
  ~ModularCombination(){
    if(del){
      delete(f);
    }
  }
  ull ncr(int r){
    //Eulars law for modular division
    ull denom = (f->fact(n-r) * f->fact(r)) % mod;
    ull mdenom = modularPower(denom,mod-2,mod);
    // ull mdenom = modularPower(f->fact(r)*modularPower(f->fact(n-r),mod-2,mod)%mod,mod-2,mod)%mod;

    ull ret = (mdenom * f->fact(n)) % mod;
    // ull ret = f->fact(n) / denom;
    return ret;
  }
};

int main(){
  int n=5;
  ull mod = (ull)1e9+7;
  ModularFactorial mf(n,mod);
  for(int i=0;i<n;i++){
    cout<<mf.fact(i)<<endl;
  }

  ModularCombination mc(n,mod);
  int x=1;
  while(x%(n+1)){
    cout<<mc.ncr(x)<<endl;
    x++;
  }
}
