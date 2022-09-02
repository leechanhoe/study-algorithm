#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N, input;
        cin >> N;
        priority_queue<long long> pq;
        
        for (int i = 0; i < N; i++){
            cin >> input;
            pq.push(-input);
        }

        long long ans = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            ans += -(a + b);
            pq.push(a + b);
        }
        cout << ans << '\n';
    }
}