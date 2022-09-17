#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, W;
int dp[1001][1001];
vector<int> path;
vector<pair<int, int>> car1, car2;

int getMinDist(int c1, int c2){
    if(c1 == W || c2 == W)
        return 0;
    if(dp[c1][c2] != -1)
        return dp[c1][c2];
    
    dp[c1][c2] = 987654321;

    int next = max(c1, c2) + 1;
    int dist1 = abs(car1[c1].first - car1[next].first) + abs(car1[c1].second - car1[next].second) + getMinDist(next, c2);
    int dist2 = abs(car2[c2].first - car2[next].first) + abs(car2[c2].second - car2[next].second) + getMinDist(c1, next);

    return dp[c1][c2] = min(dist1, dist2);
}

void backTrack(int c1, int c2){
    if(c1 == W || c2 == W)
        return;

    int next = max(c1, c2) + 1;
    int dist1 = abs(car1[c1].first - car1[next].first) + abs(car1[c1].second - car1[next].second) + getMinDist(next, c2);
    int dist2 = abs(car2[c2].first - car2[next].first) + abs(car2[c2].second - car2[next].second) + getMinDist(c1, next);

    if(dist1 < dist2){
        cout << 1 << '\n';
        backTrack(next, c2);
    }
    else{
        cout << 2 << '\n';
        backTrack(c1, next);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> W;
    memset(dp, -1, sizeof(dp));

    car1.push_back({1, 1});
    car2.push_back({N, N});
    for(int i = 0; i < W; i++){
        int y, x;
        cin >> y >> x;
        car1.push_back(make_pair(y, x));
        car2.push_back({y, x});
    }

    cout << getMinDist(0, 0) << '\n';
    backTrack(0, 0);
}