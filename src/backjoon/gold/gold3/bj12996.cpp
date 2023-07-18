#include <iostream>
#include <cstring>
using namespace std;

long long dp[51][51][51][51]; //[남은 곡 수] + [d][k][h]이 각각 불러야 하는 남은 곡 수
int S, d, k, h;

long long solve(int s, int a, int b, int c){
    if(s == 0){
        return a == 0 && b == 0 && c == 0 ? 1 : 0;
    }

    long long& ret = dp[s][a][b][c];
    if(ret != -1)
        return ret;
    ret = 0;

    ret = solve(s - 1, a - 1, b, c);
    ret += solve(s - 1, a, b - 1, c);
	ret += solve(s - 1, a, b, c - 1);
	ret += solve(s - 1, a - 1, b - 1, c);
	ret += solve(s - 1, a - 1, b, c - 1);
	ret += solve(s - 1, a, b - 1, c - 1);
	ret += solve(s - 1, a - 1, b - 1, c - 1);
    ret %= 1000000007;

    return ret;
}

int main(){
    cin >> S >> d >> k >> h;
    memset(dp, -1, sizeof(dp));
    cout << solve(S, d, k, h);
    return 0;
}