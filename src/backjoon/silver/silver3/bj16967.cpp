#include <iostream>
using namespace std;

int H, W, X, Y;
int arr[1001][1001];

int main(){
    cin >> H >> W >> X >> Y;
    int R = H + X;
    int C = W + Y;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(X <= i && Y <= j)
                arr[i][j] = arr[i][j] - arr[i-X][j-Y];
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}