#include <iostream>
using namespace std;

int N, M;
int p[10];
int ans[51];

int main(){
    cin >> N;

    int min_p = 50;
    int min_idx = 0;
    int min_p2 = 50;
    int min_idx2 = 0;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        if(0 < i && p[i] <= min_p){
            min_p = p[i];
            min_idx = i;
        }
        if (p[i] <= min_p2){
            min_p2 = p[i];
            min_idx2 = i;
        }
    }
    cin >> M;
    if(M < min_p){
        cout << 0;
        return 0;
    }
    ans[0] = min_idx;
    M -= min_p;
    int cnt = 1;
    while(min_p2 <= M){
        M -= min_p2;
        ans[cnt] = min_idx2;
        cnt++;
    }

    for(int i = 0; i < cnt; i++){
        for(int j = N - 1; j > ans[i]; j--){
            if(M + p[ans[i]] - p[j] >= 0){
                M += p[ans[i]];
                M -= p[j];
                ans[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < cnt; i++){
        cout << ans[i];
    }
    return 0;
}