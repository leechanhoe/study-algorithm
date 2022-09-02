#include<iostream>
#define MAX 1001
#define INF -987654321
using namespace std;

int N, M;
int board[MAX][MAX];
int cost[MAX][MAX][3]; // 왔던 방향으로는 다시 못가니 왔던 방향마다 따로 dp저장
bool visit[MAX][MAX];

int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};

int dfs(int y, int x, int dir){
    if(y == N - 1 && x == M - 1)
        return board[y][x];
    if(cost[y][x][dir] != INF)
        return cost[y][x][dir];
    
    visit[y][x] = true;
    int max_ = INF;
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && ny < N && 0 <= nx && nx < M){
            if(!visit[ny][nx]){
                max_ = max(max_, dfs(ny, nx, i));
            }
        }
    }
    visit[y][x] = false;
    return cost[y][x][dir] = board[y][x] + max_;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            cost[i][j][0] = INF;
            cost[i][j][1] = INF;
            cost[i][j][2] = INF;
        }
    }

    cout << dfs(0, 0, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << cost[i][j][2] << ' ';
        }
        cout << '\n';
    }
}