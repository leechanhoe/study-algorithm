#include <iostream>
using namespace std;

int m1[101][101];
int m2[101][101];
int ans[101][101];

int main()
{
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>> m1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> m2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				ans[i][j] += m1[i][k] * m2[k][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}