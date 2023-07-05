#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int R, C;
char board[MAX][MAX];
vector<pair<int, int>> fire;
bool visited[MAX][MAX];
queue<pair<pair<int, int>, int>> q;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void spread(){
    vector<pair<int, int>> nfire;
    for(auto f : fire){
        for(int i = 0; i < 4; i++){
            int nr = f.first + dr[i];
            int nc = f.second + dc[i];
            if(0 <= nr && nr < R && 0 <= nc && nc < C && board[nr][nc] != '#' && board[nr][nc] != 'F'){
                board[nr][nc] = 'F';
                nfire.push_back({nr, nc});
            }
        }
    }
    fire = nfire;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];

            if(board[i][j] == 'J'){
                if(i == 0 || i == R - 1 || j == 0 || j == C - 1){
                    cout << 1;
                    exit(0);
                }
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
            else if(board[i][j] == 'F'){
                fire.push_back({i, j});
            }
        }
    }
    int time = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(time == cnt){
            time++;
            spread();
            // for(int i = 0; i < R; i++){
            //     for(int j = 0; j < C; j++){
            //         cout << board[i][j];
            //     }
            //     cout << '\n';
            // }
        }

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < R && 0 <= nc && nc < C && board[nr][nc] && board[nr][nc] != '#' && board[nr][nc] != 'F'){
                if(nr == 0 || nr == R - 1 || nc == 0 || nc == C - 1){
                    cout << time + 1;
                    exit(0);
                }
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    // cout << nr << ' ' << nc << ' ' << cnt + 1 << '\n';
                    q.push({{nr, nc}, cnt + 1});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}