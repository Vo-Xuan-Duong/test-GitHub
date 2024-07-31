#include<iostream>
using namespace std;
void Move(int N, char A, char B, char C)
//N: so dia - A,B,C coc nguon, dich, trung gian
{
if (N==1)
cout<<"Chuyen 1 dia tu cot "<<A<<" sang cot "<<B<<endl;
else
{
Move(N-1, A, C, B);
//chuyen n-1 dia tu coc nguon sang coc trung gian
Move(1, A, B, C);
//chuyen 1 dia tu coc nguon sang coc dich
Move(N-1,C, B, A);
//chuyen n-1 dia tu coc trung gian sang coc dich
}
}
int main()
{
int n;
cout<<"Nhap so luong dia ban dau: ";
cin>>n;
cout<<"Cach chuyen nhu sau:\n";
Move(n, 'A', 'B', 'C');
}
