#include <iostream>
using namespace std;

int N;
string str;
int dp[21];

int main(){
    cin >> N >> str;

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 20; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    int repeat = 1;
    int ans = 1;
    for(int i = 0; i <= N - 8; i++){
        if(str.substr(i, 8) == "longlong"){
            repeat++;
            i += 3;
        }
        else{
            ans *= dp[repeat];
            repeat = 1;
        }
    }

    ans *= dp[repeat];
    cout << ans;
    return 0;
}