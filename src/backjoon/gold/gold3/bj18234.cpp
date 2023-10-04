#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N, T;
ll ans;
vector<pair<ll, ll>> carrot;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> T;
    carrot.resize(N);
    for(int i = 0, w, p; i < N; i++){
        cin >> w >> p;
        carrot[i] = {p, w};
    }
    sort(carrot.begin(), carrot.end());

    for(int i = 0; i < N; i++){
        ans += carrot[i].second + carrot[i].first * (T - N + i);
    }

    cout << ans;
    return 0;
}