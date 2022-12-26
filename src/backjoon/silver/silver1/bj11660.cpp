#include <iostream>
using namespace std;

int pSum[1025][1025];
int N, M, num, x1, y1, x2, y2;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num;
            pSum[i+1][j+1] = pSum[i][j+1] + pSum[i+1][j] - pSum[i][j] + num;
        }
    }

    while(M--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pSum[x2][y2] - pSum[x1-1][y2] - pSum[x2][y1-1] + pSum[x1-1][y1-1] << '\n';
    }
    return 0;
}