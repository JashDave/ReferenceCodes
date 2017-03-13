/*
  g++ -std=c++11 Lambdas.cpp
  References:
  http://blog.smartbear.com/c-plus-plus/c11-tutorial-lambda-expressions-the-nuts-and-bolts-of-functional-programming/
  C++11 Tutorial: Lambda Expressions — The Nuts and Bolts of Functional Programming
*/


#include <iostream>
//#include <initializer_list>  /* included by defautl on use, but may be required explicitly for some compilers. */

using namespace std;

int main(){
  /*Lambda Syntax
    [capture clause] (parameters) -> return-type {body}
    Capture clauses : [=] : capture all of the variables from the enclosing scope by value
                      [&] : capture all of the variables from the enclosing scope by reference
                      [this] : capture all of the data members of the enclosing class
                      [var1, var2&] : captures each variables explicitly
    (parameters) : can be skiped if not required, but recommended to be used for clearity.
    -> return-type : can be skiped, and can be determined by compiler, but some compilers may not support this so it's recommended to use is explicitly.
  */

  /*
  //http://en.cppreference.com/w/cpp/language/lambda
  struct S2 { void f(int i); };
  void S2::f(int i)
  {
      [&]{}; //ok: by-reference capture default
      [=]{}; //ok: by-copy capture default
      [&, i]{}; // ok: by-reference capture, except i is captured by copy
      [=, &i]{}; // ok: by-copy capture, except i is captured by reference
      [&, &i] {}; // error: by-reference capture when by-reference is the default
      [=, this] {}; // error: this when = is the default
      [=, *this]{}; // ok: captures the enclosing S2 by copy (C++17)
      [i, i] {}; // error: i repeated
      [this, *this] {}; // error: "this" repeated (C++17)
  }
  */
  int a=10;
  long long l=100;

  /* Pass by copy */
  [=]()->void{ int b = a*2; cout<<b<<endl;}() ;
  // [=]()->void{ a=a+1;} ; //Throws error as a is passed by copy
  [&]()->void{ a=a+1; cout<<a<<endl; }() ;
  cout<<a<<endl;
  [&a,l]()->void{ a=l+1; cout<<a<<endl; }() ;
  cout<<a<<endl;
  return 0;
}
