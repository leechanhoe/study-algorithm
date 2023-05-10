#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<int ,pair<int, int>> a, pair<int, pair<int, int>> b){
    if(a.second.first == b.second.first){
        return a.second.second < b.second.second;
    }
    return a.second.first > b.second.first;
}

int N, C;
map<int, pair<int, int>> m;

int main(){
    cin >> N >> C;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(m.find(x) == m.end())
            m[x] = {1, i};
        else
            m[x].first++;
    }

    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].second.first; j++){
            cout << v[i].first << ' ';
        }
    }
    return 0;
}