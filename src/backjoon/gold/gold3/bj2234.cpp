#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int area[51][51];
int areaSize[51][51];
int wall[51][51];
bool visit[51][51];
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int bfs(int sr, int sc, int id){
    vector<pair<int, int>> v;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    visit[sr][sc] = true;
    while(!q.empty()){
        v.push_back(q.front());
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            if((wall[r][c] & (1 << i)) == 0){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(0 <= nr && nr < M && 0 <= nc && nc < N && !visit[nr][nc]){
                    q.push({nr, nc});
                    visit[nr][nc] = true;
                }
            }
        }
    }

    int s = v.size();
    for(int i = 0; i < s; i++){
        areaSize[v[i].first][v[i].second] = s;
        area[v[i].first][v[i].second] = id;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> wall[i][j];
        }
    }

    int id = 0;
    int maxArea = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                maxArea = max(bfs(i, j, id), maxArea);
                id++;
            }
        }
    }

    int maxArea2 = 0;
    for(int r = 0; r < M; r++){
        for(int c = 0; c < N; c++){
            for(int i = 0; i < 4; i++){
                if((wall[r][c] & (1 << i)) != 0){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];

                    if(0 <= nr && nr < M && 0 <= nc && nc < N && area[r][c] != area[nr][nc]){
                        maxArea2 = max(maxArea2, areaSize[r][c] + areaSize[nr][nc]);
                    }
                }
            }
        }
    }

    cout << id << '\n' << maxArea << '\n' << maxArea2;
    return 0;
}