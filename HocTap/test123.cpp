#include <iostream>
#include <unordered_map>

using namespace std;

// Hàm tính số Fibonacci thứ n
char fibonacci(int n, unordered_map<int, char>& memo) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    if (n == 1) {
        return 'A';
    } else if (n == 2) {
        return 'B';
    } else {
        char result = fibonacci(n - 2, memo) + fibonacci(n - 1, memo);
        memo[n] = result;
        return result;
    }
}

// Hàm tìm ký tự thứ m trong chuỗi Fibonacci thứ n
char find_char_at_m(int n, int m) {
    unordered_map<int, char> memo;
    return fibonacci(n, memo)[m - 1];
}

int main() {
    int N = 6;
    int M = 10;
    cout << "Ký tự thứ " << M << " trong chuỗi Fibonacci thứ " << N << " là: " << find_char_at_m(N, M) << endl;

    return 0;
}
