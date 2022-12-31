#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, t;
int con[11];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<int>());

    if(N <= M){
        cout << v[0];
        return 0;
    }

    for(int i = 0; i < M; i++){
        pq.push(v[i]);
    }

    for(int i = M; i < N; i++){
        int tmp = pq.top() + v[i];
        pq.pop();
        pq.push(tmp);
    }

    for(int i = 0; i < M-1; i++){
        pq.pop();
    }
    cout << pq.top();
    return 0;
}