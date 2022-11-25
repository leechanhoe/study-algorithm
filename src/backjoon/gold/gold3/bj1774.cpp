#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int N, M;
int parent[1002];
double ans;
vector<pair<int, int>> coord;
vector<pair<double, pair<int, int>>> edge;

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

double getDistance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        parent[i] = i;
    
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        coord.push_back(make_pair(a, b));
    }

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        if(find(a) != find(b))
            uni(a, b);
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            edge.push_back({getDistance(coord[i].first, coord[i].second, coord[j].first, coord[j].second), make_pair(i + 1, j + 1)});
        }
    }
    sort(edge.begin(), edge.end());

    double ans = 0;
    for(int i = 0; i < edge.size(); i++){
        if(find(edge[i].second.first) != find(edge[i].second.second)){
            uni(edge[i].second.first, edge[i].second.second);
            ans += edge[i].first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}