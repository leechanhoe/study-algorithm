#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[3];
int mindp[2][3];
int maxdp[2][3];

int main(){
    cin >> N;

    cin >> board[0] >> board[1] >> board[2];
    for(int i = 0; i < 3; i++)
        mindp[0][i] = maxdp[0][i] = board[i];
    for(int i = 1; i < N; i++){
        cin >> board[0] >> board[1] >> board[2];

        for(int j = 0; j < 3; j++)
            maxdp[1][j] = mindp[1][j] = board[j];

        mindp[1][0] += min(mindp[0][0], mindp[0][1]);
        maxdp[1][0] += max(maxdp[0][0], maxdp[0][1]);

        mindp[1][1] += min({mindp[0][0], mindp[0][1], mindp[0][2]});
        maxdp[1][1] += max({maxdp[0][0], maxdp[0][1], maxdp[0][2]});

        mindp[1][2] += min(mindp[0][1], mindp[0][2]);
        maxdp[1][2] += max(maxdp[0][1], maxdp[0][2]);

        for(int j = 0; j < 3; j++){
            mindp[0][j] = mindp[1][j];
            maxdp[0][j] = maxdp[1][j];
        }
    }
    cout << max({maxdp[0][0], maxdp[0][1], maxdp[0][2]}) << ' ' << min({mindp[0][0], mindp[0][1], mindp[0][2]});
}