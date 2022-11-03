#include<iostream>
using namespace std;

int N, M, a, b, ans;
int parent[500000];

int find(int x){
    if (parent[x] != x)
        return parent[x] = find(parent[x]);
    return parent[x];
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) 
        return true;
    else{
        parent[a] = b;
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++){
        cin >> a >> b;
        if (uni(a, b)){
            ans = i;
            break;
        }
    }

    if (ans == 0)
        cout << 0;
    else 
        cout << ans;
    return 0;
}