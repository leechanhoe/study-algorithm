#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while(1){
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0){
            return 0;
        }

        int** dp = new int*[N];
        for(int i = 0; i < N; i++){
            dp[i] = new int[M];
            for(int j = 0; j < M; j++){
                cin >> dp[i][j];
            }
            if(M > 1)
            dp[i][1] = max(dp[i][0], dp[i][1]);
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 2; j < M; j++){
                dp[i][j] = max(dp[i][j-1], dp[i][j] + dp[i][j-2]);
            }
        }

        M--;
        if(N > 1)
            dp[1][M] = max(dp[1][M], dp[0][M]);
        for(int i = 2; i < N; i++){
            dp[i][M] = max(dp[i-1][M], dp[i][M] + dp[i-2][M]);
        }
        cout << dp[N-1][M] << '\n';
    }
}