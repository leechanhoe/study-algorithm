#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, t, ans;
vector<int> v;
vector<int> diff;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> t;

    v.push_back(t);
    for(int i = 1; i < N; i++){
        cin >> t;
        diff.push_back(t - v[i-1]);
        v.push_back(t);
    }
    sort(diff.begin(), diff.end(), greater<int>());

    ans = v[N-1] - v[0] + 1;
    for(int i = 0; i < K - 1; i++){
        ans -= diff[i] - 1;
    }
    cout << ans;
    return 0;
}