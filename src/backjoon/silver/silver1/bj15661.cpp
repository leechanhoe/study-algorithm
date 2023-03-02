#include <iostream>
using namespace std;

int s[21][21];
int N;

int search(int a){
    int t1 = 0, t2 = 0;
    for(int i = 0; i < N; i++){
        int b = (a >> i) & 1;
        for(int j = i + 1; j < N; j++){
            if(b == ((a >> j) & 1)){
                if(b)
                    t1 += s[i][j] + s[j][i];
                else
                    t2 += s[i][j] + s[j][i];
            }
        }
    }
    return abs(t1 - t2);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> s[i][j];
    }

    int limit = 1 << (N - 1);
    int ans = 987654321;
    for(int i = 1; i < limit; i++){
        ans = min(ans, search(i));
    }
    cout << ans;
    return 0;
}