#include<bits/stdc++.h>
//#include<vector>
using namespace std;

//vector < kieu du lieu> ten_vector
//push_back()  thêm vào phần tử

//size() : kích thước vector
//truy cap cac phan tu trong vector thong qua chi so
//duyet thong qua index
//duyet thong qua for each
//duyet bằng iterator
//vector<int> v;
//vector<int> v(n);
//vector<int> v( n, value);

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << v.size() << endl;
    cout << "phan tu dau tien " << v[0] << endl;
    cout << "phan tu cuoi cung trong vector "<< v[v.size()-1] << endl;
    // for ( int i  = 0; i < v.size(); i ++){
    //     cout << v[i] << " ";
    // }
    for(int x : v){
        cout << x << endl ;
    }
    v.erase()
    for( vector<int> :: iterator it = v.begin(); it != v.end(); ++it){//cach 2:      for( auto it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
    }
    int n;cin >> n;
    vector<int> v(n, 0);//khai báo vector nhưng đã có sẵn n phần tử v[n]
    //int a[n];
    for( int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    v.push_back(20);
    //cach 2:
    
    int n ; cin >> n;
    vector<int > v;
     for( int i= 0; i< n; i++){
        int x; cin >> x;
        v.push_back(x);
     }
    
   string s = " ngon ngu  lap trinh python";
   stringstream ss(s);
   string tmp;
   //vector<string> v;
   while (ss >> tmp)
   {
    v.push_back(tmp);
   }
   for(string x: v){
    cout << x << endl;
   }

    return 0;
}
