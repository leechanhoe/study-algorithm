#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;

ll dp[32][32], I;
int N, L;
string ans;

ll solve(int n, int l){
    if(dp[n][l] != -1)
        return dp[n][l];
    if(n == 0 || l == 0)
        return dp[n][l] = 1;

    dp[n][l] = solve(n-1, l);
    if(l > 0)
        dp[n][l] += solve(n-1, l-1);
    return dp[n][l];
}

void find(int n, int l, ll i){
    if(n == 0)
        return;
    
    if(l == 0){
        for(int i = 0; i < n; i++){
            ans += '0';
        }
        return;
    }

    ll num = solve(n-1, l);
    if(num >= i){
        ans += '0';
        find(n-1, l, i);
    }
    else{
        ans += '1';
        find(n-1, l-1, i-num);
    }
}

int main(){
    cin >> N >> L >> I;
    memset(dp, -1, sizeof(dp));

    find(N, L, I);
    cout << ans << '\n';
    return 0;
}