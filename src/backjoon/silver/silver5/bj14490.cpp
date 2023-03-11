#include <bits/stdc++.h>
using namespace std;

int N, M, gcd1;

int getGcd(int a, int b){
    return b == 0 ? a : getGcd(b, a % b);
}

int main(){
    scanf("%d:%d", &N, &M);
    gcd1 = getGcd(N, M);
    cout << N / gcd1 << ":" << M / gcd1;
    
    return 0;
}