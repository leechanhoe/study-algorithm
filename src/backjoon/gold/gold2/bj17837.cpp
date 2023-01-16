#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class piece{
    public:
    int r, c, d;

    piece(int r, int c, int d) {
        this->r = r;
        this->c = c;
        this->d = d;
    }

    void inverse(){
        switch (d)
        {
        case 1:
            d = 2;
            break;
        case 2:
            d = 1;
            break;
        case 3:
            d = 4;
            break;
        case 4:
            d = 3;
            break;
        }
    }
};

int N, K;
int mv[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int color[14][14];
vector<int> board[14][14];
piece* p[11];

bool white(int i, int r, int c, int nr, int nc){
    int cnt = board[nr][nc].size();
    while(1){
        int idx = board[r][c].back();
        board[nr][nc].push_back(idx);
        p[idx]->r = nr;
        p[idx]->c = nc;
        board[r][c].pop_back();

        if(idx == i)
            break;
    }

    if(board[nr][nc].size() >= 4)
        return true;

    reverse(board[nr][nc].begin() + cnt, board[nr][nc].end());
    return false;
}

bool red(int i, int r, int c, int nr, int nc){
    while(1){
        int idx = board[r][c].back();
        board[nr][nc].push_back(idx);
        p[idx]->r = nr;
        p[idx]->c = nc;
        board[r][c].pop_back();
        
        if(idx == i)
            break;
    }

    if(board[nr][nc].size() >= 4)
        return true;
    return false;
}

bool blue(int i, int r, int c){
    // cout << i << " d : " << p[i]->d << " -> ";
    p[i]->inverse();
    // cout << i << " d : " << p[i]->d << '\n';
    int nr = r + mv[p[i]->d][0];
    int nc = c + mv[p[i]->d][1];
    if(color[nr][nc] != 2)
        return white(i, r, c, nr, nc);
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= N+1; j++){
            if(i == 0 || j == 0 || i == N+1 || j == N+1)
                color[i][j] = 2;
            else
                cin >> color[i][j];
        }
    }

    for(int i = 1; i <= K; i++){
        int r, c, d;
        cin >> r >> c >> d;
        p[i] = new piece(r, c, d);
        board[r][c].push_back(i);
    }

    int turn = 0;
    bool flag = false;
    while(++turn <= 1000){
        for(int i = 1; i <= K; i++){
            int r = p[i]->r;
            int c = p[i]->c;
            int nr = r + mv[p[i]->d][0];
            int nc = c + mv[p[i]->d][1];
            if(color[nr][nc] == 0){
                flag = white(i, r, c, nr, nc);
            }
            else if(color[nr][nc] == 1){
                flag = red(i, r, c, nr, nc);
            }
            else{
                // flag = blue(i, r, c);
                p[i]->inverse();
                int nr = r + mv[p[i]->d][0];
                int nc = c + mv[p[i]->d][1];
                if(color[nr][nc] != 2)
                    i--;
            }

            if(flag){
                break;
            }
        }
        // for(int a : board[1][4]){
        //     cout << a << ' ';
        // }
        // cout << '\n';
        // for(int i = 1; i <= K; i++){
        //     cout << i << " : " << p[i]->r << ' ' << p[i]->c << '\n';
        // }
        if(flag){
            break;
        }
        // cout << '\n';
    }

    cout << (turn > 1000 ? -1 : turn);
    return 0;
}