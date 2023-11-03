#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int arr[52][52];
tuple<int, int, int> cmd[6];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int dr2[4] = {1, 0, -1, 0};
int dc2[4] = {0, 1, 0, -1};
bool visited[6];
int ans = 987654321;

void rotate_arr(int nowr, int nowc, int s, bool inverse){
    if(s == 0)
        return;
    
    int r = nowr - s;
    int c = nowc - s;
    int now = arr[r][c];
    int next;
    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < s * 2; i++){
            int nr = r + (inverse ? dr2[dir] : dr[dir]);
            int nc = c + (inverse ? dc2[dir] : dc[dir]);
            next = arr[nr][nc];
            arr[nr][nc] = now;
            now = next;
            r = nr;
            c = nc;
        }
    }
    rotate_arr(nowr, nowc, s - 1, inverse);
}

int check_min(){
    int min_ = 987654321;
    for(int i = 1; i <= N; i++){
        min_ = min(min_, accumulate(arr[i] + 1, arr[i] + M + 1, 0));
    }
    return min_;
}

void dfs(int n){
    if(n == 0){
        ans = min(ans, check_min());
        return;
    }

    for(int i = 0; i < K; i++){
        if(!visited[i]){
            visited[i] = true;
            rotate_arr(get<0>(cmd[i]), get<1>(cmd[i]), get<2>(cmd[i]), false);
            dfs(n-1);
            rotate_arr(get<0>(cmd[i]), get<1>(cmd[i]), get<2>(cmd[i]), true);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0, r, c, s; i < K; i++){
        cin >> r >> c >> s;
        cmd[i] = make_tuple(r, c, s);
    }

    dfs(K);
    cout << ans;
    return 0;
}