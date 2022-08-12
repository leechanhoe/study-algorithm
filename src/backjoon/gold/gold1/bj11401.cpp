#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;
int N, K;

ll pow(ll a, ll b) {
    if (b == 0)
        return 1;

    ll half = pow(a, b / 2) % MOD;
    return (b % 2 ? (((half * half) % MOD) * a): (half * half)) % MOD;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
	ll a = 1, b = 1; //a = n!, b = k!(n-k)!
	for (ll i = 1; i <= N; i++) {
		a *= i;
		a %= MOD;
	}
	for (ll i = 1; i <= K; i++) {
		b *= i;
		b %= MOD;
	}
	for (ll i = 1; i <= N - K; i++) {
		b *= i;
		b %= MOD;
	}
    ll b2 = pow(b, MOD-2);
    cout << (a * b2) % MOD;
}