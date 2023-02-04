#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, x, y, z;
int parent[200001];
vector<pair<int, pair<int, int>>> edge;

int find(int x){
    if(x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if(a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0)
            return 0;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        edge.clear();
        int sum = 0;
        for(int i = 0; i < m; i++){
            cin >> x >> y >> z;
            edge.push_back({z, {x, y}});
            sum += z;
        }
        sort(edge.begin(), edge.end());

        for(int i = 0; i < m; i++){
            if(find(edge[i].second.first) != find(edge[i].second.second)){
                sum -= edge[i].first;
                uni(edge[i].second.first, edge[i].second.second);
            }
        }
        cout << sum << '\n';
    }
}