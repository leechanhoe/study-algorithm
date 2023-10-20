#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int board[102][102];
bool visited[102][102];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int cheese;

void spread_air(){
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    board[0][0] = -1;

    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(0 <= nr && nr <= N + 1 && 0 <= nc && nc <= M + 1 && !visited[nr][nc] && board[nr][nc] <= 0){
                visited[nr][nc] = true;
                board[nr][nc] = -1;
                q.push({nr, nc});
            }
        }
    }
}

void melt(){
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            if(board[r][c] != 1)
                continue;

            int air = 0;
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(board[nr][nc] == -1){
                    air++;
                }
            }

            if(2 <= air){
                board[r][c] = -2;
                cheese--;
            }
        }
    }
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            if(board[r][c] == -2)
                board[r][c] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
            if(board[i][j])
                cheese++;
        }
    }

    int time = 0;
    while(1){
        spread_air();
        melt();
        time++;

        if(cheese == 0)
            break;
    }

    cout << time;
    return 0;
}