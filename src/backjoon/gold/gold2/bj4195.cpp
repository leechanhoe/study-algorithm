#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int cnt[200001];
map<string, int> id;

int find2(int x){
    if(x != parent[x])
        parent[x] = find2(parent[x]);
    return parent[x];
}

void uni(int a, int b){
    a = find2(a);
    b = find2(b);

    if(a != b){
        cnt[a] = cnt[b] = cnt[a] + cnt[b];
    }

    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        id.clear();
        int F, idNum = 0;
        for(int i = 0; i < 200001; i++){
            parent[i] = i;
            cnt[i] = 1;
        }

        cin >> F;
        for(int i = 0; i < F; i++){
            string a, b;
            cin >> a >> b;
            if(id.find(a) == id.end())
                id[a] = idNum++;
            if(id.find(b) == id.end())
                id[b] = idNum++;

            uni(id[a], id[b]);
            cout << cnt[parent[id[a]]] << '\n';
        }
    }
}