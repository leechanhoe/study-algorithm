#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int note[1000001];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> note[i];
        }
        sort(note, note + N);

        cin >> M;
        int note2;
        for (int i = 0; i < M; i++){
            cin >> note2;
            cout << binary_search(note, note + N, note2) << '\n';
        }
    }
    return 0;
}