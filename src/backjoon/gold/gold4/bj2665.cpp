#include <iostream>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

char board[51][51];
int broke[51][51];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++){
            
            board[i][j] = input[j];
            broke[i][j] = 987654321;
        }
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));

    while(!q.empty()){
        int r = get<0>(q.front());
        int c = get<1>(q.front());
        int b = get<2>(q.front());
        q.pop();
        
        for(auto dir : mv){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(0 <= nr && nr < n && 0 <= nc && nc < n){
                if(board[nr][nc] == '0' && broke[nr][nc] > b){
                    q.push(make_tuple(nr, nc, b + 1));
                    broke[nr][nc] = b + 1;
                }
                else if(board[nr][nc] == '1' && broke[nr][nc] > b){
                    q.push(make_tuple(nr, nc, b));
                    broke[nr][nc] = b;
                }
            }
        }
    }
    cout << broke[n-1][n-1];
    return 0;
}