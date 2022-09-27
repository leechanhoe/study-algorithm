#include <iostream>
#include <vector>
using namespace std;
 
int N, M, K;
int parent[51];
vector<int> know;
vector<int> party[51];
 
 
int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}
 
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}
 
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
 
    while (K--) {
        int t;
        cin >> t;
        know.push_back(t);
    }
 
    for (int i = 1; i <= N; i++) 
        parent[i] = i;

    for (int i = 0; i < M; i++) {
        int num, now, prev;
        cin >> num;
        for (int j = 0; j < num; j++) {
            if (j >= 1) {
                prev = now;
                cin >> now;
                uni(prev, now);
            }
            else {
                cin >> now;
            }
            party[i].push_back(now);
        }
    }

    int ans = M;
    for(int i = 0; i < M; i++){
        for(auto& man : party[i]){
            bool brk = false;
            for(auto& k : know){
                if(find(man) == find(k)){
                    ans--;
                    brk = true;
                    break;
                }
            }
            if(brk)
                break;
        }
    }

    cout << ans;
}