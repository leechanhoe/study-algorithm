#include <bits/stdc++.h>
using namespace std;

int N, M, D, ans;
int orig_board[18][18];
int board[18][18];
bool visited[18][18];
int dr[3] = {0, -1, 0};
int dc[3] = {-1, 0, 1};
set<pair<int, int>> s;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] = orig_board[i][j];
        }
    }
}

void next_round(){
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            board[i][j] = board[i-1][j];
        }
    }
}

void kill(){
    for(auto data : s){
        board[data.first][data.second] = 0;
    }
}

bool is_game_end(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j]){
                return false;
            }
        }
    }

    return true;
}

void bfs(int c){
    if(board[N-1][c]){
        s.insert({N-1, c});
        return;
    }

    for(int i = 0; i < N; i++){
        memset(visited[i], 0, M * sizeof(bool));
    }
    queue<pair<pair<int, int>, int>> q;
    vector<pair<int, int>> enumy;
    q.push({{N-1, c}, 1});
    visited[N-1][c] = true;
    int limit = D;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if(limit == d){
            if(enumy.empty())
                return;

            sort(enumy.begin(), enumy.end());
            s.insert({enumy[0].second, enumy[0].first});
            return;
        }

        for(int i = 0; i < 3; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < N && 0 <= nc && nc < M && !visited[nr][nc]){
                if(board[nr][nc] == 1){
                    limit = d + 1;
                    enumy.push_back({nc, nr});
                }
                visited[nr][nc] = true;
                q.push({{nr, nc}, d + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> orig_board[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            for(int k = j + 1; k < M; k++){
                init();
                int score = 0;
                for(int round = 0; round < N; round++){
                    bfs(i);
                    bfs(j);
                    bfs(k);
                    score += s.size();
                    kill();
                    s.clear();
                    if(is_game_end())
                        break;
                    next_round();
                }

                ans = max(ans, score);
            }
        }
    }
    cout << ans;
    return 0;
}