#include <iostream>
using namespace std;

int parent[10001], price[10001];
int N, M, k;

int find(int x) {
	if (parent[x] != x)
        parent[x] = find(parent[x]);
 	return parent[x];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (price[a] > price[b])
        parent[a] = b;
	else 
        parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
		parent[i] = i;
	}

	int a, b;
	price[0] = 10001;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		uni(a, b);
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		int par = find(i);
		if (par != find(0)) {
			result += price[par];
			uni(0, i);
		}
	}
	if (k >= result)
        cout << result;
	else 
        cout << "Oh no";
	return 0;
}