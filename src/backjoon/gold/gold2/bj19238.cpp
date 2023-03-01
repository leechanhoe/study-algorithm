#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[22][22];
pair<int, int> dest[444];
int N, M, fuel;
int taxi[3]; // r, c, 태운 승객
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

// bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
//     if(a.first < b.first)
//         return true;
//     else if(a.first == b.first){
//         return a.second.first < b.second.first;
//     }
//     return false;
// }

void bfs(){
    if(taxi[2] == 0 && board[taxi[0]][taxi[1]] > 1){
        taxi[2] = board[taxi[0]][taxi[1]];
        board[taxi[0]][taxi[1]] = 0;
        return;
    }

    bool** visit = new bool*[N+1];
    for(int i = 0; i <= N; i++)
        visit[i] = new bool[N+1]{false};
    
    queue<pair<int, pair<int, int>>> q;
    q.push({taxi[0], {taxi[1], fuel}});
    visit[taxi[0]][taxi[1]] = true;
    vector<pair<int, pair<int, int>>> find;
    int findDist = 987654321;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second.first;
        int nf = q.front().second.second - 1;
        if(!find.empty() && findDist > nf)
            break;
        if(nf < 0){
            cout << -1;
            exit(0);
        }
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if(0 < nr && nr <= N && 0 < nc && nc <= N && !visit[nr][nc] && board[nr][nc] != 1){
                visit[nr][nc] = true;
                q.push({nr, {nc, nf}});
                if(taxi[2] == 0 && board[nr][nc] >= 2){
                    find.push_back({nr, {nc, board[nr][nc]}});
                    findDist = nf;
                    continue;
                }
                else if(taxi[2] > 0 && nr == dest[taxi[2]].first && nc == dest[taxi[2]].second){ // 승객 태우고 목적지 도달
                    taxi[0] = nr;
                    taxi[1] = nc;
                    taxi[2] = 0;
                    fuel += fuel - nf;
                    return;
                }
            }
        }
    }
    if(find.empty()){
        cout << -1;
        exit(0);
    }
    sort(find.begin(), find.end());
    taxi[0] = find[0].first;
    taxi[1] = find[0].second.first;
    taxi[2] = find[0].second.second;
    board[taxi[0]][taxi[1]] = 0;
    fuel = findDist;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> fuel;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cin >> board[i][j];
    }
    cin >> taxi[0] >> taxi[1];
    for(int i = 2; i <= M + 1; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        board[a][b] = i;
        dest[i].first = c;
        dest[i].second = d;
    }

    for(int i = 0; i < M; i++){
        bfs();
        // cout << (taxi[2] - 1) << ' ' << fuel << ' ';
        bfs();
        // cout << fuel << '\n';
    }
    cout << fuel;
    return 0;
}