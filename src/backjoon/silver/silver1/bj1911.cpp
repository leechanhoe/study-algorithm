#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L;
pair<int, int> puddle[10001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> puddle[i].first >> puddle[i].second;
    }
    sort(puddle, puddle + N);

    int now = 0, need, ans = 0;
    for(int i = 0; i < N; i++){
        if(puddle[i].second <= now)
            continue;

        now = max(puddle[i].first, now);
        need = (int)ceil((float)(puddle[i].second - now) / L);
        now += need * L;
        ans += need;
    }
    cout << ans;
    return 0;
}