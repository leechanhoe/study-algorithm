#include <iostream>
using namespace std;

int gcd(int a, int b){
    return a % b ? gcd(b, a%b) : b;
}

int main() {
    int N, first, ring;

    cin >> N >> first;
    for(int i = 1; i < N; i++){
        cin >> ring;
        int tmp = gcd(first, ring);
        cout << first / tmp << "/" << ring / tmp << '\n';
    }
}