#include <iostream>
using namespace std;

int N, M, K;
int p[100001];
int s[100001];
int ans = 987654321;

int cnt, n, r;
int order[4];

void combination(int now, int pos)
{
	if (now == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << s[order[i]] << " ";

		}
		cout << endl;
 
		return;
	}
 
	for (int idx = pos; idx < n; idx++)
	{
		order[now] = idx;
		combination(now + 1, idx + 1);
	}
}

int main() {
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		cin >> p[i];
	}
	for(int i = 0; i < M; i++){
		cin >> s[i];
	}

	combination(5, 2);
	
	cout << ans;
	return 0;
}