#include <iostream>

using namespace std;

int parent[100001];
int G, P, cnt;

int find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> G >> P;
    for(int i = 1;i <= G;i++)
        parent[i] = i;

    for (int i = 0; i <= P; i++){
        int gi;
        cin >> gi;
        int doc = find(gi);

        if(doc == 0)
            break;

        cnt++;
        parent[doc] = find(parent[doc-1]);
    }
    cout << cnt << "\n";
	return 0;
}