#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int N, s, e;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> course;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s >> e;
        course.push_back({s, e});
    }
    sort(course.begin(), course.end());
    pq.push(course[0].second);

    for(int i = 1; i < N; i++){
        while(!pq.empty() && pq.top() <= course[i].first)
            pq.pop();
        pq.push(course[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}