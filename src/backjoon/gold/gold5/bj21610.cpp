#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[50][50];
bool** cloud;
int mv[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

void move(int d, int s){
    bool** ncloud = new bool*[N];
    for(int i = 0; i < N; i++)
        ncloud[i] = new bool[N]{false};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cloud[i][j]){
                int nr = (i + mv[d][0] * s) % N;
                int nc = (j + mv[d][1] * s) % N;
                nr = nr < 0 ? nr + N : nr;
                nc = nc < 0 ? nc + N : nc;
                ncloud[nr][nc] = true;
            }
        }
        delete cloud[i];
    }
    delete cloud;
    cloud = ncloud;
}

void rain(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cloud[i][j]){
                board[i][j]++;
            }
        }
    }
}

void copy(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cloud[i][j]){
                for(int k = 2; k <= 8; k+=2){
                    int nr = i + mv[k][0];
                    int nc = j + mv[k][1];
                    if(nr < 0 || N <= nr || nc < 0 || N <= nc)
                        continue;

                    if(board[nr][nc] > 0)
                        board[i][j]++;
                }
            }
        }
    }
}

void make_cloud(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] >= 2 && !cloud[i][j]){
                cloud[i][j] = true;
                board[i][j] -= 2;
            }
            else{
                cloud[i][j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    cloud = new bool*[N];
    for(int i = 0; i < N; i++)
        cloud[i] = new bool[N]{false};
    cloud[N-1][0] = cloud[N-1][1] = cloud[N-2][0] = cloud[N-2][1] = true;

    while(M--){
        int d, s;
        cin >> d >> s;
        move(d, s);
        rain();
        copy();
        make_cloud();
        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans += board[i][j];
        }
    }
    cout << ans;
    return 0;
}