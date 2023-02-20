#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> line;
priority_queue<int, vector<int>, greater<int>> pq;
int n, d, ans;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int h, o;
        cin >> h >> o;
        if(h > o)
            line.push_back({o, h});
        else
            line.push_back({h, o});
    }
    cin >> d;
    sort(line.begin(), line.end(), cmp);

    for(int i = 0; i < n; i++){
        int start = line[i].first;
        int end = line[i].second;

        if(end - start > d)
            continue;

        pq.push(start);
        while(!pq.empty()){
            if(pq.top() + d >= end)
                break;
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}