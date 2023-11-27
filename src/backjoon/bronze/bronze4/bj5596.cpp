#include <bits/stdc++.h>
using namespace std;

int S[4];
int T[4];

int main(){
    for(int i = 0; i < 4; i++){
        cin >> S[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> T[i];
    }

    cout << max(accumulate(S, S + 4, 0), accumulate(T, T + 4, 0));
}