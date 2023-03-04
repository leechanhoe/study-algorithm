#include <iostream>
using namespace std;

int N, M, K;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    if(K < N + M - 1){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            cout << (i + j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}