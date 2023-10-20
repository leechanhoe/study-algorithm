#include <bits/stdc++.h>
using namespace std;

int N, K, R;
int field[101][101];
pair<int, int> cow[101];
bool load[101][101][4];
bool meet[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void input(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> R;
    for(int i = 0; i < R; i++){
        int r, c, rr, cc, difr, difc;
        cin >> r >> c >> rr >> cc;
        difr = r - rr;
        difc = c - cc;
        if(difr == -1){
            load[r][c][2] = true;
            load[rr][cc][0] = true;
        }
        else if(difc == 1){
            load[r][c][3] = true;
            load[rr][cc][1] = true;
        }
        else if(difr == 1){
            load[r][c][0] = true;
            load[rr][cc][2] = true;
        }
        else if(difc == -1){
            load[r][c][1] = true;
            load[rr][cc][3] = true;
        }
    }

    for(int i = 1; i <= K; i++){
        cin >> cow[i].first >> cow[i].second;
        field[cow[i].first][cow[i].second] = i;
    }
}

bool visited[101][101];
void bfs(){
    for(int i = 1; i <= K; i++){
        memset(visited, false, sizeof(visited));
        queue<pair<int,int>> q;
        q.push({cow[i].first, cow[i].second});
        visited[cow[i].first][cow[i].second] = true;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(0 < nr && nr <= N && 0 < nc && nc <= N && !visited[nr][nc] && !load[r][c][d]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                    meet[i][field[nr][nc]] = true;
                }
            }
        }
    }
}

void check_meet(){
    int cant = 0;
    for(int i = 1; i <= K; i++){
        for(int j = i + 1; j <= K; j++){
            if(!meet[i][j])
                cant++;
        }
    }

    cout << cant;
}

int main(){
    input();
    bfs();
    check_meet();
    return 0;
}