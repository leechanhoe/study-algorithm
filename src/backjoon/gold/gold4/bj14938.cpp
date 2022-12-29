#include <iostream>
#define INF 987654321
using namespace std;

int n, m, r, a, b, l;
int item[101];
int dist[101][101];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> item[i];
        for(int j = 1; j <= n; j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < r; i++){
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int get = 0;
        for(int j = 1; j <= n; j++){
            if(dist[i][j] <= m){
                get += item[j];
            }
        }
        ans = max(ans, get);
    }
    cout << ans;
    return 0;
}