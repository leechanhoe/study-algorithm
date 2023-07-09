#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
pair<pair<int, int>, int> log[100001];
int id[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        log[i] = {{x1, x2}, i};
    }
    sort(log + 1, log + N + 1);

    int idx = 1;
    id[log[1].second] = idx;
    int start = log[1].first.first;
    int end = log[1].first.second;
    // cout << start << ' ' << end << '\n';
    for(int i = 2; i <= N; i++){
        if(log[i].first.second <= end){
            id[log[i].second] = idx;
        }
        else{
            if(end < log[i].first.first){
                start = log[i].first.first;
                id[log[i].second] = ++idx;
            }
            else{
                id[log[i].second] = idx;
            }
            end = log[i].first.second;
        }
    }

    for(int i = 0; i < Q; i++){
        int q1, q2;
        cin >> q1 >> q2;
        cout << (id[q1] == id[q2] ? 1 : 0) << '\n';
    }
    return 0;
}