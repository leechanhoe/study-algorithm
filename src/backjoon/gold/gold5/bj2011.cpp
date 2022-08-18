#include <iostream>
#include <string.h>
#define MOD 1000000
using namespace std;

int dp[5001];
int arr[5001];
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int len = s.length();
    for(int i = 1; i <= len; i++){
        arr[i] = s[i-1] - '0';
    }

    if (arr[1] == 0){
        cout << 0;
        return 0;
    }

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= len; i++){
        int tmp = arr[i-1] * 10 + arr[i];
        if (tmp == 0){
            cout << 0;
            return 0;
        }
        if (0 < arr[i] && arr[i] < 10)
            dp[i] = dp[i-1];
        if (10 <= tmp && tmp <= 26)
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        // cout << dp[i] << ' ';
    }
    cout << dp[len];
}