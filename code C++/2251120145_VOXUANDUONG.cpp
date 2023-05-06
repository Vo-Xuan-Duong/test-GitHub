#include <iostream>
using namespace std;
//xây dựng hàm kiểm tra số nguyên tố (1 : là số nguyên tố ;0 ; ko là số nguyên tố)
int (TestSNT(int m));


int main()
{
    int n,dem=0,tong =0;
    cout<< "nhap n:";
    cin>>n;
    //xuất các số nguyên tố nhỏ hơn n
    for(int i=1;i<=n;i++)
        if (TestSNT(i)==1)
        {
            cout<<i<<" la so nguyen to";
            dem++;
            tong+=i;
        }
        if (dem>0)
        cout<<"Trung binh cong cac so nguyen to la:"<<(float)tong/dem;

    return 0;
}
//Dinh nghia ham TestSNT(int m)
int TestSNT(int m)
{
    int flag=1;
    int i=2;
    while (flag&&(i<m))
    {
        if (m%i==0)
            flag =0;
        i++;
    }
    return flag;
}
