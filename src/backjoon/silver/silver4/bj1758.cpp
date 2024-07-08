#include <bits/stdc++.h>
using namespace std;

int N;
int tip[100001];
long long ans;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tip[i];
    }

    sort(tip, tip + N, greater<>());

    for(int i = 0; i < N; i++){
        if (tip[i] > i){
            ans += tip[i] - i;
        }
    }

    cout << ans;
    return 0;
}