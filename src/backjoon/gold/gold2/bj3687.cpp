#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
typedef long long ll;

ll dp[101];

void makeMax(vector<int>& v, int remain){
    if(!remain)
        return;
    if(remain == 3){
        v.push_back(7);
        return;
    }

    v.push_back(1);
    makeMax(v, remain - 2);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int minNum[8] = {0, 0, 1, 7, 4, 2, 0, 8}; // 성냥을 쓰는 숫자중 최소
    int tc;

    memset(dp, 0x7f , sizeof(dp));
    dp[1] = 9; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;
    for (int i = 8; i <= 100 ; i++) { 
		for (int j = 2; j <= 7 ; j++) 
			dp[i] = min(dp[i], dp[i-j] * 10 + minNum[j]);
    }

    cin >> tc;
    while(tc--){
        vector<int> maxV;
        int n;
        cin >> n;

        cout << dp[n] << ' ';

        makeMax(maxV, n);
        for (int i = maxV.size() - 1; i >= 0; i--)
		    cout << maxV[i];
        cout << '\n';
    }
}