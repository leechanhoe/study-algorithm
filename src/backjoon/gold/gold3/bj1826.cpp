#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, L, P;
pair<int, int> station[10001];
priority_queue<int> pq;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> station[i].first >> station[i].second;
    cin >> L >> P;

    sort(station, station + N);

    int i = 0, ans = 0;
    while(P < L){
        while(i < N && P >= station[i].first){
            pq.push(station[i].second);
            i++;
        }

        if (pq.empty()){
            ans = -1;
            break;
        }
        P += pq.top();
        pq.pop();
        ans++;
    }
    cout << ans;
}