#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int N, M, W;

struct edge {
    int s, e, t;
};

bool bellmanFord(int n, vector<edge> edges) {
    vector<int> dist(n + 1, MAX);

    dist[1] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < edges.size(); j++){
            if (dist[edges[j].e] > dist[edges[j].s] + edges[j].t) {
				dist[edges[j].e] = dist[edges[j].s] + edges[j].t;
			}
        }
    }

    for (int j = 0; j < edges.size(); j++){
        if (dist[edges[j].e] > dist[edges[j].s] + edges[j].t) {
            return true;
		}
    }
    return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	int s, e, t;
	while (TC--) {
		cin >> N >> M >> W;

		vector<edge> edges;

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, t});
			edges.push_back({e, s, t});
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			edges.push_back({s, e, -t});
		}

		if (bellmanFord(N, edges))
            cout << "YES\n";
		else 
            cout << "NO\n";
	}
}