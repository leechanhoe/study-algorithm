#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, nx, ny, ans;
pair<int, int> broke[5001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> broke[i].first >> broke[i].second;
    }
    sort(broke, broke + M);
    
    x = broke[0].first;
    y = broke[0].second;
    for(int i = 1; i < M; i++){
        nx = broke[i].first;
        ny = broke[i].second;
        if(nx <= y && y < ny)
            y = ny;
        else if(y < nx){
            ans += y-x;
            x = nx;
            y = ny;
        }
    }
    cout << N - (ans + (y - x));
    return 0;
}