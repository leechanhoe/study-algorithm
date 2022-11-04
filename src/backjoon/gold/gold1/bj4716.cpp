#include <bits/stdc++.h>
using namespace std;

int N, A, B;
int need[1001], distA[1001], distB[1000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1){
        priority_queue<pair<int, int>> pq;
        int ans = 0;
        
        cin >> N >> A >> B;
        if(N == 0 && A == 0 && B == 0)
            break;

        for(int i = 0; i < N; i++){
            cin >> need[i] >> distA[i] >> distB[i];
            pq.emplace(abs(distA[i] - distB[i]), i);
        }

        while(!pq.empty()){
            int here = pq.top().second;
            pq.pop();

            int& getfrom = (distA[here] > distB[here] ? B : A);
            if(getfrom) {
                int cnt = min(getfrom, need[here]);
                getfrom -= cnt;
                need[here] -= cnt;
                ans += cnt * min(distA[here], distB[here]);
            }
            ans += max(distA[here], distB[here]) * need[here];
        }
        cout << ans << '\n';
    }
    return 0;
}