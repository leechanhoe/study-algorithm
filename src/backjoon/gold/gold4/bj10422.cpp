#include <iostream>
using namespace std;

long long dp[5001];

long long recur(int len){
    if(len == 0)
        return 1;

    if(dp[len] > 0)
        return dp[len];

    for (int i = 2; i <= len; i += 2){
        dp[len] += recur(i - 2) * recur(len - i);
        dp[len] %= 1000000007;
    }
    return dp[len];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;

    while(tc--){
        int len;
        cin >> len;
        if(len % 2 == 0)
            cout << recur(len) << '\n';
        else
            cout << "0\n";
    }
}