#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int sensor[10001];

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> sensor[i];    
    sort(sensor, sensor + N);

    vector<int> dist(N-1, 0);
    for(int i = 0; i < N-1; i++)
        dist[i] = sensor[i+1] - sensor[i];
    sort(dist.begin(), dist.end());

    int ans = 0;
    for(int i = 0; i < N-K; i++)
        ans += dist[i];
    cout << ans;
    return 0;
}