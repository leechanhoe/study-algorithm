#include <iostream>
#include <string>
using namespace std;
#define MOD 1234567891

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int L;
    long long ans = 0, r = 1;
    string str;

    cin >> L >> str;
    for (int i = 0; i < L; i++){
        long long tmp = str[i] - 'a' + 1;
        ans += (tmp * r) % MOD;
        ans %= MOD;
        r = (r * 31) % MOD;
    }
    cout << ans;
}