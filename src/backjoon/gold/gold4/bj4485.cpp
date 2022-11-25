#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define INF 987654321
#define MAX 130
using namespace std;
typedef tuple<int,int,int> P;

int N;
int board[MAX][MAX];
int dist[MAX][MAX];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void init(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++)
            dist[i][j] = INF;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int tc = 1;
    while(1){
        cin >> N;
        if(N == 0)
            return 0;

        init();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cin >> board[i][j];
        }
    
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(make_tuple(board[0][0], 0, 0));
        dist[0][0] = board[0][0];

        while(!pq.empty()){
            int y, x, cost;
            tie(cost, y, x) = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(0 <= ny && ny < N && 0 <= nx && nx < N){
                    int ncost = cost + board[ny][nx];
                    if(dist[ny][nx] <= ncost)
                        continue;
                    dist[ny][nx] = ncost;
                    pq.push(P(dist[ny][nx], ny, nx));
                }
            }
        }
        cout << "Problem " << tc++ << ": " << dist[N-1][N-1] << '\n';
    }
}