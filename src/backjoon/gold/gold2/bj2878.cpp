#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N, M;
ll candy[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    ll cant = 0;
    for(int i = 0; i < N; i++){
        cin >> candy[i];
        cant += candy[i];
    }
    sort(candy, candy + N);
    cant -= M;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll tmp = min(candy[i], cant / (N - i));
        ans += tmp * tmp;
        cant -= tmp;
    }
    cout << ans;
    return 0;
}