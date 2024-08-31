#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, ma = 0, sum = 0;
    vector<pair<int, int>> p;
    cin >> N;
    for(int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        p.push_back({x, y});
    }

    for(int i = 1; i < N - 1; i++){
        int dif1 = abs(p[i].first - p[i-1].first) + abs(p[i].second - p[i-1].second);
        int dif2 = abs(p[i].first - p[i+1].first) + abs(p[i].second - p[i+1].second);
        int dif3 = abs(p[i-1].first - p[i+1].first) + abs(p[i-1].second - p[i+1].second);
        sum += dif1;
        if(i == N - 2)
            sum += dif2;
        ma = max(ma, dif1 + dif2 - dif3);
    }
    cout << (sum - ma);
}