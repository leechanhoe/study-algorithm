#include <iostream>
using namespace std;
 
int factorial(int t) {
    int ret = 1;
    for (int i = t; i > 0; i--) {
        ret *= i;
    }
    return ret;
}
 
int main() {
    int N, K;
    cin >> N >> K;
 
    int result = factorial(N) / (factorial(K) * factorial(N - K));
 
    cout << result;
}