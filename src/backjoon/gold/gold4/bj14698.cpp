#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long mod = 1000000007;
int T, N;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        long long c, ans = 1;
        cin >> N;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < N; i++){
            cin >> c;
            pq.push(c);
        }

        while(pq.size() > 1){
            long long a = pq.top() % mod;
            pq.pop();
            long long b = pq.top() % mod;
            pq.pop();
            ans = ans * ((a * b) % mod) % mod;
            pq.push(a * b);
        }
        cout << ans << '\n';
    }
    return 0;
}