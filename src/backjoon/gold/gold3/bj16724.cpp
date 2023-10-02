#include <iostream>
using namespace std;

int N, M, ans;
char zone[1001][1001];
int visited[1001][1001];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c){
    visited[r][c] = 1;

    int i;
    switch (zone[r][c])
            {
            case 'U':
                i = 0;
                break;
            case 'R':
                i = 1;
                break;
            case 'D':
                i = 2;
                break;
            case 'L':
                i = 3;
                break;
            }
    int nr = r + dr[i];
    int nc = c + dc[i];
    if(visited[nr][nc] == 1)
        ans++;
    if(visited[nr][nc] == 0){
        dfs(nr, nc);
    }
    visited[r][c] = 2;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> zone[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == 0)
                dfs(i, j);
        }
    }
    
    cout << ans;
    return 0;
}