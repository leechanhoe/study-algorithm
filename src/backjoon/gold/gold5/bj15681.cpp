#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
bool visit[100001];
int sizes[100001];
int node, query, s, e;

int dfs(int n){
    if (sizes[n])
        return sizes[n];

    visit[n] = true;
    int siz = 1;
    for (int i = 0; i < adj[n].size(); i++){
        int next = adj[n][i];
        if (!visit[next])
            siz += dfs(next);
    }
    sizes[n] = siz;
    return siz;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int root;
    cin >> node >> root >> query;

    for (int i = 0; i < node - 1; i++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
    sizes[root] = dfs(root);
    for (int i = 0; i < query; i++) {
		cin >> s;
		cout << sizes[s] << '\n';
	}
}