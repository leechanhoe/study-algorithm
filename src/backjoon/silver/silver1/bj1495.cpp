#include <iostream>
#include <algorithm>
using namespace std;

bool dp[51][1001];
int N, S, M;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S >> M;
    dp[0][S] = true;
    for(int i = 1; i <= N; i++){
        int v;
        cin >> v;

        for(int j = 0; j <= M; j++){
            if(dp[i-1][j]){
                if(j >= v)
                    dp[i][j-v] = true;
                if(j + v <= M)
                    dp[i][j+v] = true;
            }
        }
    }
    
    int ans = -1;
    for(int i = 0; i <= M; i++)
        if(dp[N][i])
            ans = i;
    cout << ans;
    return 0;
}