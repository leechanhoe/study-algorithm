#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
pair<int, int> q[10000];
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> q1, pair<int, int> q2){
    if (q1.first == q2.first)
        return q1.second > q2.second;
    return q1.first < q2.first;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> q[i].second >> q[i].first;
    
    sort(q, q + N, cmp);
    for (int i = 0; i < N; i++){
        if (pq.size() >= q[i].first){ // 핵심로직 - 최소힙의 크기를 데드라인 이하로 항상 유지한다
            if (pq.top() < q[i].second){ // 3초면 3문제를 풀수있고 5초면 5문제까지 풀수 있기 때문
                pq.pop(); // 최소힙의 크기를 넘으면 최소힙에서 제일 작은 컵라면을 뺴준다
                pq.push(q[i].second);
            }
        }
        else
            pq.push(q[i].second);
    }
    int l = pq.size();
    int ans = 0;
    for (int i = 0; i < l; i++){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}