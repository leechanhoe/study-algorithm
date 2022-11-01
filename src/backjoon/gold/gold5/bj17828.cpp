#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, X;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> X;

	if (26 * N < X || X < N){
		cout << "!\n";
		return 0;
	}
	
	string ans;
	for (int i = 0; i < N; i++){
		ans += 'A';
	}
	X -= N;

	for (int i = N - 1; i >= 0 && X > 0; i--){
		int az = min(X, 25);
		ans[i] += az;
		X -= az;
	}
	cout << ans;
	return 0;
}