#include <iostream>
#include <cstring>
using namespace std;

int N, d1, d2, M;
int closet[21];
int dp[21][21][21];

int f(int idx, int le, int ri){
    if (idx == M)
        return 0;
    if (dp[idx][le][ri])
        return dp[idx][le][ri];
    dp[idx][le][ri] = min(abs(le - closet[idx]) + f(idx + 1, closet[idx], ri), abs(ri - closet[idx]) + f(idx + 1, le, closet[idx]));
    return dp[idx][le][ri];
}

int main(){
    cin >> N;
    cin >> d1 >> d2;
    cin >> M;
    
    for (int i = 0; i < M; i++)
        cin >> closet[i];
    cout << f(0, d1, d2);
}