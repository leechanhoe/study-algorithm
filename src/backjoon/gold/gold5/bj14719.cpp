#include <iostream>
using namespace std;

int H, W, ans;
int block[501];

int main(){
    cin >> H >> W;

    for(int i = 0; i < W; i++){
        cin >> block[i];
    }

    for(int i = 1; i < W - 1; i++){
        int le = 0;
        int ri = 0;

        for(int j = 0; j < i; j++){
            le = max(le, block[j]);
        }

        for(int j = i + 1; j < W; j++){
            ri = max(ri, block[j]);
        }

        ans += max(0, min(le, ri) - block[i]);
    }
    cout << ans;
    return 0;
}