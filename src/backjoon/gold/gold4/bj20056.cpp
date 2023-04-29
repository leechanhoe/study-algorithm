#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Ball{
    int r;
    int c;
    int m;
    int s;
    int d;
};

int N, M, K;
vector<Ball> board[51][51];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void move(){
    vector<Ball> nboard[51][51];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < board[i][j].size(); k++){
                Ball b = board[i][j][k];

                b.r += dir[b.d][0] * b.s;
                b.c += dir[b.d][1] * b.s;
                if(b.r < 1) b.r = (b.r + N * 1000 - 1) % N + 1;
                else if(b.r > N) b.r = (b.r - 1) % N + 1;
                if(b.c < 1) b.c = (b.c + N * 1000 - 1) % N + 1;
                else if(b.c > N) b.c = (b.c - 1) % N + 1;

                nboard[b.r][b.c].push_back(b);
            }
        }
    }
    copy(&nboard[0][0], &nboard[0][0] + 51 * 51, &board[0][0]);
}

void divide(){
    vector<Ball> nboard[51][51];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j].size() > 1){
                int msum = 0, ssum = 0;
                int dnum = board[i][j][0].d;
                bool sameDir = true;
                for(int k = 0; k < board[i][j].size(); k++){
                    Ball b = board[i][j][k];
                    msum += b.m;
                    ssum += b.s;
                    if(dnum % 2 != b.d % 2)
                        sameDir = false;
                }

                int newM = msum / 5;
                int newS = ssum/board[i][j].size();
                if(newM == 0)
                    continue;

                for(int k = 0; k < 8; k += 2){
                    if(sameDir)
                        nboard[i][j].push_back(Ball{i, j, newM, newS, k});
                    else
                        nboard[i][j].push_back(Ball{i, j, newM, newS, k+1});
                }
            }
            else if(board[i][j].size() == 1)
                nboard[i][j].push_back(board[i][j][0]);
        }
    }
    copy(&nboard[0][0], &nboard[0][0] + 51 * 51, &board[0][0]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    int r, c, m, s, d;
    for(int i = 0; i < M; i++){
        cin >> r >> c >> m >> s >> d;
        Ball b{r, c, m, s, d};
        board[r][c].push_back(b);
    }

    while(K--){
        move();
        divide();
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < board[i][j].size(); k++)
                ans += board[i][j][k].m;
        }
    }
    cout << ans;
    return 0;
}