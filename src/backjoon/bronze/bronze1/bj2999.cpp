#include <iostream>
using namespace std;

string msg;
int N, R, C;
char mat[101][101];

int main(){
    cin >> msg;

    N = msg.size();
    for(int i = N; i >= 1; i--){
        if(N % i == 0){
            if(N / i > i)
                break;

            C = i;
            R = N / C;
        }
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 1; j <= N; j++){
    //         if(i * j == N){
    //             if(i > j)
    //                 break;
    //             R = i;
    //             C = j;
    //         }
    //     }
    // }

    int idx = 0;
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R; j++){
            mat[j][i] = msg[idx];
            idx++;
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << mat[i][j];
        }
    }
    return 0;
}