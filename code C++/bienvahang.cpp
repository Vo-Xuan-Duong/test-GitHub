/*
    biến : giá trị thay đổi đc
    hằng : giá trị không thể thay đổi , gán giá trị khi cấp phát.

    Có 2 cách khai báo hằng
     + Sử dụng #define
     + Sử dụng từ khóa const
    
*/

#include <iostream>
using namespace std;

int main(){
    //Biến
    int x=5 ;
    cout << x << "\n";
    x = 10;
    cout << x << "\n";
    cout << "hellowordl" << endl;
}