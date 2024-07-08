#include <bits/stdc++.h>
using namespace std;

int N, K;
int cnt[21];
string name[300001];
long long ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> name[i];
    }

    for(int i = 0; i < N; i++){
        ans += cnt[name[i].size()];
        
        cnt[name[i].size()]++;
        if (i >= K){
            cnt[name[i-K].size()]--;
        }
    }

    cout << ans;
    return 0;
}