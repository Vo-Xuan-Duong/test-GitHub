/*
int     =>      4 bytes => kiểu số nguyên
float   =>      4 bytes => kiểu số thực
double  =>      8 bytes => kiểu số thực
boolean =>      1 bytes => kiểu 2 giá trị (đúng / sai)
char    =>      1 bytes => kiểu lưu dữ được 1 giá trị bất kì mà bạn nhập
string  =>      không phải là built- in data type ; được dung thương xuyên.
*/
#include <iostream>
using namespace std;

int main(){
    //kiểu số nguyên
    int age = 20;
    cout<< age << "\n";//  "\n" in kí tự xuống hàng
    int v = 3e8; // e hoặc E đại diện cho 10 mũ
    cout << v << endl;  // end line in kí tự xuống hàng

    //kiểu só thực
    float width = 2.5;// lưa được sau dấu phẩy 6 chữ số
    cout << width << "\n";
    double height = 3.5;// lưu được sau đấu phẩy 15 chữ số 
    cout << height << "\n";
    
    // kiểu dữ kiệu đúng sai
    bool sao = true;
    cout << sao << "\n";

    // kiểu string
    string bran_name = "lap trinh khong kho nhung lai qua kho";
    cout << bran_name << endl;
    system("pause");

} 