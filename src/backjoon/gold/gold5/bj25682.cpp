#include <iostream>
using namespace std;

int N, M, K;
int b[2001][2001];
int w[2001][2001];

int solve(char first){

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char c;
            cin >> c;
            b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1];
            w[i][j] = w[i][j-1] + w[i-1][j] - w[i-1][j-1];

            if((i + j) % 2 == 0){
                if(c == 'B')
                    w[i][j]++;
                else
                    b[i][j]++;
            }
            else{
                if(c == 'B')
                    b[i][j]++;
                else
                    w[i][j]++;
            }
        }
    }
    
    int ans = 987654321;
    for(int i = K; i <= N; i++){
        for(int j = K; j <= M; j++){
            ans = min(ans, b[i][j] - b[i-K][j] - b[i][j-K] + b[i-K][j-K]);
            ans = min(ans, w[i][j] - w[i-K][j] - w[i][j-K] + w[i-K][j-K]);
        }
    }

    cout << ans;
    return 0;
}