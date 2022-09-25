#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
        q.push(i);

	cout << "<";
	while (q.size() > 1) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
            q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">\n";
}
