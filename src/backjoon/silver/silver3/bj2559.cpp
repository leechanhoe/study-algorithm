#include <iostream>
using namespace std;

int sum[100001];
int N, K, arr, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> N >> K >> arr;
    if(N == 1){
        cout << arr;
        return 0;
    }
    sum[0] = arr;
    for(int i = 1; i < N; i++){
        cin >> arr;
        sum[i] = sum[i-1] + arr;
    }

    ans = sum[K-1];
    for(int i = K; i < N; i++){
        ans = max(ans, sum[i] - sum[i-K]);
    }

    cout << ans;
}