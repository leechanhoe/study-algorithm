#include <iostream>
#include <vector>
#define INF 123456789
using namespace std;

// int N, start, en, M;
// pair<pair<int, int>, int> tran[51];
// int cost[51];

// vector<long long> dist;

// int fw_adj[51][51];
// int fw_dist[51][51];

// bool floyd(int n, int s, int e){
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             if (i == j)
//                 fw_dist[i][j] = 0;
//             else if (fw_adj[i][j] != 0)
//                 fw_dist[i][j] = fw_adj[i][j];
//             else
//                 fw_dist[i][j] = INF;
//         }
//     }

//     for(int k = 0; k < N; k++){
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < N; j++){
//                 fw_dist[i][j] = min(fw_dist[i][j], fw_dist[i][k] + fw_dist[k][j]);
//             }
//         }
//     }

//     return fw_dist[s][e] == INF ? false : true;
// }

// int main(){
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> start >> en >> M;
//     for(int i = 0; i < M; i++){
//         cin >> tran[i].first.first >> tran[i].first.second >> tran[i].second;
//         fw_adj[tran[i].first.first][tran[i].first.second] = 1;
//     }

//     for(int i = 0; i < N; i++){
//         cin >> cost[i];
//     }

//     for(int i = 0; i < M; i++){
//         for(int j = 0; j < N; j++){
//             if(tran[i].first.second == j){
//                 tran[i].second -= cost[j];
//             }
//         }
//     }

//     dist.assign(N, INF);
//     dist[start] = -cost[start];

//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < M; j++){
//             int from = tran[j].first.first;
//             int to = tran[j].first.second;
//             int co = tran[j].second;
//             long long next_cost = co + dist[from];

//             if(dist[from] == INF)
//                 continue;
//             if(dist[to] > next_cost){
//                 dist[to] = next_cost;
//             }
//         }
//     }

//     bool flag = false;
//     for(int i = 0; i < M; i++){
//         int from = tran[i].first.first;
//         int to = tran[i].first.second;
//         int co = tran[i].second;
//         long long next_cost = co + dist[from];

//         if(dist[from] == INF)
//             continue;
//         if(dist[to] > next_cost){
//             if(floyd(N, from, en))
//                 flag = true;
//         }
//     }

//     if(dist[en] == INF)
//         cout << "gg";
//     else{
//         if (flag) {
// 			cout << "Gee";
// 		}
// 		else {
// 			cout << -dist[en];
// 		}
//     }
        
//     return 0;
// }

typedef pair<pair<int, int>, int> edge; // start, end, cost
vector<edge> e;
vector<long long> dist;
int city[50];
int FW_adj[50][50];
int FW_dist[50][50];

bool FW(int n, int start , int end) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				FW_dist[i][j] = 0;
			else if (FW_adj[i][j] != 0)
				FW_dist[i][j] = FW_adj[i][j];
			else
				FW_dist[i][j] = INF;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				FW_dist[a][b] = min(FW_dist[a][b], FW_dist[a][k] + FW_dist[k][b]);
			}
		}
	}

	if (FW_dist[start][end] == INF)
		return 0;
	else
		return 1;
}

int main() {
	int n, from, to, m;
	cin >> n >> from >> to >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		e.push_back({ {start,end }, cost });
		FW_adj[start][end] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i].first.second == j) {
				e[i].second -= city[j];
			}
		}
	}



	dist.assign(n, INF);
	dist[from] = -city[from];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e.size(); j++) {
			int start = e[j].first.first;
			int end = e[j].first.second;
			int cost = e[j].second;
			long long next_cost = cost + dist[start];
			if (dist[start] == INF)
				continue;
			if (dist[end] > next_cost) {
				dist[end] = next_cost;
			}
		}
	}


	int flag = 0;
	for (int i = 0; i < e.size(); i++) {
		int start = e[i].first.first;
		int end = e[i].first.second;
		int cost = e[i].second;
		long long next_cost = cost + dist[start];
		if (dist[start] == INF)
			continue;
		if (dist[end] > next_cost) {
			if (FW(n, start, to)) {
				flag = 1;
			}
		}
	}

	if (dist[to] == INF) {
		cout << "gg";
	}
	else {
		if (flag == 1) {
			cout << "Gee";
		}
		else {
			cout << -dist[to];
		}
	}

}