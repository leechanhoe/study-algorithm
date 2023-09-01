#include <iostream>
#include <queue>
using namespace std;

enum Side{
    EAST,
    SOUTH,
    WEST,
    NORTH,
    UP,
    DOWN
};

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int N, M, K;
int dice[6] = {3, 5, 4, 2, 1, 6};
int dir = EAST;
pair<int, int> loc = {1, 1};
int tmp[6];
int board[21][21];
int ans;

bool can_move(){
    int nr = loc.first + dr[dir];
    int nc = loc.second + dc[dir];
    if(0 < nr && nr <= N && 0 < nc && nc <= M)
        return true;
    else
        return false;
}

void move(){
    loc.first += dr[dir];
    loc.second += dc[dir];

    for(int i = 0; i < 6; i++){
        tmp[i] = dice[i];
    }

    if(dir == EAST){
        tmp[UP] = dice[WEST];
        tmp[DOWN] = dice[EAST];
        tmp[EAST] = dice[UP];
        tmp[WEST] = dice[DOWN];
    }
    else if(dir == SOUTH){
        tmp[UP] = dice[NORTH];
        tmp[DOWN] = dice[SOUTH];
        tmp[SOUTH] = dice[UP];
        tmp[NORTH] = dice[DOWN];
    }
    else if(dir == WEST){
        tmp[UP] = dice[EAST];
        tmp[DOWN] = dice[WEST];
        tmp[EAST] = dice[DOWN];
        tmp[WEST] = dice[UP];
    }
    else if(dir == NORTH){
        tmp[UP] = dice[SOUTH];
        tmp[DOWN] = dice[NORTH];
        tmp[SOUTH] = dice[DOWN];
        tmp[NORTH] = dice[UP];
    }

    for(int i = 0; i < 6; i++){
        dice[i] = tmp[i];
    }
}

int rotate(int clock){
    if(clock == 1){
        switch (dir)
        {
        case EAST:
            return SOUTH;
        case SOUTH:
            return WEST;
        case WEST:
            return NORTH;
        case NORTH:
            return EAST;
        }
    }
    else{
        switch (dir)
        {
        case EAST:
            return NORTH;
        case SOUTH:
            return EAST;
        case WEST:
            return SOUTH;
        case NORTH:
            return WEST;
        }
    }
}

int reverse(){
    switch (dir)
    {
        case EAST:
            return WEST;
        case SOUTH:
            return NORTH;
        case WEST:
            return EAST;
        case NORTH:
            return SOUTH;
    }
}

bool visited[21][21];
int get_score(int nowr, int nowc, int val){
    int score = val;

    for(int i = 0; i < 21; ++i) {
        for(int j = 0; j < 21; ++j) {
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    q.push({nowr, nowc});
    visited[nowr][nowc] = true;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 < nr && nr <= N && 0 < nc && nc <= M && !visited[nr][nc] && board[nr][nc] == val){
                score += val;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    return score;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }
    
    while(K--){
        if(!can_move())
            dir = reverse();
        move();

        ans += get_score(loc.first, loc.second, board[loc.first][loc.second]);
        
        if(dice[DOWN] < board[loc.first][loc.second])
            dir = rotate(-1);
        else if(dice[DOWN] > board[loc.first][loc.second])
            dir = rotate(1);
        // cout << loc.first << ' ' << loc.second << ' ' << dir << ' ' << dice[DOWN] << '\n';
    }

    cout << ans;
    return 0;
}