#include <iostream>
#include <queue>
using namespace std;

int N, G, M;
pair<int, int> oil[10001];

int main() {
	cin >> N >> G >> M;
	
	for(int i = 0; i < M; i++){
		cin >> oil[i].first;
	}
	for(int i = 0; i < M; i++){
		cin >> oil[i].second;
	}
	
	if(N <= G){
		cout << 0;
		return 0;
	}
	
	int ans = 0;
	priority_queue<int> pq;
	for(int i = 0; i < M; i++){
		if(oil[i].first <= G)
			pq.push(oil[i].second);
		if(oil[i].first > G){
			while(!pq.empty() && oil[i].first > G){
				// cout << "1 : "<< pq.top() << '\n';
				G += pq.top();
				pq.pop();
				ans++;
			}
			if(oil[i].first > G){
				ans = -1;
				break;
			}
		}
	}
	while(!pq.empty() && N > G){
		// cout << "2 : "<< pq.top() << '\n';
		G += pq.top();
		pq.pop();
		ans++;
	}
	if(N > G)
		cout << -1;
	else
		cout << ans;
	return 0;
}