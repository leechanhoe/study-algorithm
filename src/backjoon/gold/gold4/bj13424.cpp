#include <iostream>
#define INF 987654321
using namespace std;

int T;
int dist[101][101];
int mate[101];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        int N, M, K;
        cin >> N >> M;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }

        for(int i = 0, a, b, c; i < M; i++){
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> mate[i];
        }

        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int total = INF;
        int ans = 0;
        for(int i = 1; i <= N; i++){
            int tmp = 0;
            for(int j = 0; j < K; j++){
                tmp += dist[i][mate[j]];
            }
            if(tmp < total){
                total = tmp;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}