#include <iostream>
#include <vector>
#include <cstring>
#define INF 10001
using namespace std;

int N, M, sum;
int m[101], c[101];
int dp[101][10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];
	}

    // dp[i][j] = i번째 앱까지 탐색했을 때 j비용을 소모해서 얻을 수 있는 최대 메모리
    for (int i = 1; i <= N; i++){
		for (int j = 0; j <= sum; j++){
			if (j - c[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]] + m[i]);
			
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

    for (int i = 0; i <= sum; i++){
		if (dp[N][i] >= M){
			cout << i << endl;
			break;
		}	
	}
}   