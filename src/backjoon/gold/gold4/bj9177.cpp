#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[201][201];
int tc;
string a, b, c;

int f(int i, int j){
    if(i + j == c.size())
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i < a.size() && c[i+j] == a[i] && f(i + 1, j))
        return dp[i][j] = 1;
    if(j < b.size() && c[i+j] == b[j] && f(i, j + 1))
        return dp[i][j] = 1;

    return dp[i][j] = 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> a >> b >> c;
        memset(dp, -1, sizeof(dp));
        string ans = f(0, 0) ? "yes" : "no";
        cout << "Data set " << i << ": " << ans << '\n'; 
    }
    return 0;
}