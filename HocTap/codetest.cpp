#include <iostream>
#include <vector>
#include <list>


using namespace std;

 template<typename T>
 class Less_than {
 const T val; 
// value to compare against
 public:
 Less_than(const T& v) :val{v} { }
 bool operator()(const T& x) const { return x<val; } // call operator
 };


template <typename C, typename P>
    //repuires Sequence<C> && Callable<P, Value_type<P>>
int count(const C& x, P pred){
    int cnt = 0;
    for(const auto& x :c){
        if(pred(x)) ++cnt;
    }
    return cnt;
}

 void f(const vector<int>& vec, const list<string>& lst, int x, const string& s)
 {
    cout << "number of values less than " << x << ": " << count(vec,Less_than{x}) << '\n';
    cout << "number of values less than " << s << ": " << count(lst,Less_than{s}) << '\n';
 }


int main(){
    Less_than iti(42);
    Less_than its("Backus");


    bool b1  = iti(22);
    cout << b1 << endl;
    

}