#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int parent[502];
// bool tree[502];

// int find(int x){
//     if(parent[x] != x)
//         parent[x] = find(parent[x]);
//     return parent[x];
// }

// void uni(int a, int b){
//     a = find(a);
//     b = find(b);

//     if(a > b)
//         parent[b] = a;
//     else
//         parent[a] = b;
// }

// int main(){
//     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//     int tc = 1;
//     while(1){
//         int n, m, n1, n2, T = 0;
//         cin >> n >> m;

//         if(n == 0 && m == 0)
//             return 0;

//         for(int i = 1; i <= n; i++){
//             parent[i] = i;
//             tree[i] = true;
//         }

//         for(int i = 0; i < m; i++){
//             cin >> n1 >> n2;
//             if(find(n1) == find(n2)){
//                 tree[find(n1)] = false;
//             }
//             else
//                 uni(n1, n2);
//         }

//         for(int i = 1; i <= n; i++){
//             int tmp = find(i);
//             if(tree[tmp]){
//                 T++;
//                 tree[tmp] = false;
//             }
//         }

//         cout << "Case " << tc++ << ": ";
//         if(T > 1){
//             cout << "A forest of " << T << " trees.";
//         }
//         else if(T == 1){
//             cout << "There is one tree.";
//         }
//         else{
//             cout << "No trees.";
//         }
//         cout << '\n';
//     }
// }

int N, M, cnt;
bool visited[555];
vector<int> adj[555];

bool DFS(int curr, int justbefore) {
	visited[curr] = true;

	for (auto child : adj[curr]) {
		if (child == justbefore) continue;
		// cycle 이 생기면
		if (visited[child]) return false;
		if (DFS(child, curr) == false) return false;
	}
	return true;
}
int main() {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
while (1) {
	cin >> N >> M;
	if (N == 0 && M == 0) break;
	
	// 초기화
	int ans = 0; // 트리 개수
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= N; ++i) adj[i].clear();

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
		if (!visited[i])
			if (DFS(i, 0)) ans++;

	cout << "Case " << ++cnt;
	if (ans == 0) cout << ": No trees.";
	else if (ans == 1) cout << ": There is one tree.";
	else cout << ": A forest of " << ans << " trees.";
	cout << '\n';
}
return 0;
}