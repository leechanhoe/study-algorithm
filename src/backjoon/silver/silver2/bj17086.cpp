#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int board[51][51];
int ans;
bool visited[51][51];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1 ,0, 1};

void bfs(int nowr, int nowc){
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({{nowr, nowc}, 0});
    visited[nowr][nowc] = true;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for(int dir = 0; dir < 8; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(0 <= nr && nr < N && 0 <= nc && nc < M && !visited[nr][nc]){
                if(board[nr][nc] == 1){
                    ans = max(ans, dist + 1);
                    return;
                }
                visited[nr][nc] = true;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!board[i][j])
                bfs(i, j);
        }
    }

    cout << ans;
    return 0;
}