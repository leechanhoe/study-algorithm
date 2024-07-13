#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, int> m;
priority_queue<pair<int, int>> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        int P, L;
        cin >> P >> L;
        m[P] = L;
        pq1.push({L, P});
        pq2.push({L, P});
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "recommend"){
            int x;
            cin >> x;
            if(x == 1){
                while(m[pq1.top().second] != pq1.top().first){
                    pq1.pop();
                }
                cout << pq1.top().second << '\n';
            }
            else if(x == -1){
                while(m[pq2.top().second] != pq2.top().first){
                    pq2.pop();
                }
                cout << pq2.top().second << '\n';
            }
        }
        else if(cmd == "add"){
            int p, l;
            cin >> p >> l;
            m[p] = l;
            pq1.push({l, p});
            pq2.push({l, p});
        }
        else if(cmd == "solved"){
            int x;
            cin >> x;
            m[x] = 0;
        }
    }
    return 0;
}