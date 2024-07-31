#include <iostream>

using namespace std;

int n, k, a[1000], temp;

//nhi phan
// void ktao(){
//     for(int i = 0; i < n; i ++){
//         a[i] = 0;
//     }
// }

// void sinh(){
//     int i = n;
//     while(i >= 0 && a[i] == 1){
//         a[i] = 0;
//         i--;
//     }
//     if(i == 0){
//         temp = 0;
//     }else {
//         a[i] = 1;
//     }
// }


//chinh hop ko lap chap k

void ktao1(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}

void sinh1(){
    int i = k;
    while(i >=1 && a[i] == n-k+i){
        i--;
    }
    if(i == 0){
        temp = 0;
    }else {
        a[i]++;
        for(int j = i + 1; j <= k ; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}




int main(){
    cin >> n >> k;
    temp = 1;
    ktao1();
    while(temp){
        for(int i = 1; i <= k; i++){
            cout << a[i] ;
        }
        cout << endl;
        sinh1();
    }


    return 0;
}