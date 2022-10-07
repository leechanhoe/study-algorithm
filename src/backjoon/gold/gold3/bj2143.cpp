#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int N, M;
ll T;
ll a[1001], b[1001];
vector<ll> aSum, bSum;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }

    for(int i = 0; i < N; i++){
        ll sum = a[i];
        aSum.push_back(sum);
        for(int j = i + 1; j < N; j++){
            sum += a[j];
            aSum.push_back(sum);
        }
    }

    for(int i = 0; i < M; i++){
        ll sum = b[i];
        bSum.push_back(sum);
        for(int j = i + 1; j < M; j++){
            sum += b[j];
            bSum.push_back(sum);
        }
    }

    sort(aSum.begin(), aSum.end());
    sort(bSum.begin(), bSum.end());
    ll ans = 0;
    for(auto& aa : aSum){
        int lo = lower_bound(bSum.begin(), bSum.end(), T - aa) - bSum.begin();
        int up =upper_bound(bSum.begin(), bSum.end(), T - aa) - bSum.begin();
        ans += up - lo;
    }
    cout << ans;
}