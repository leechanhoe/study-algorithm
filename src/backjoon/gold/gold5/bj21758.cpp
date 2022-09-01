#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[100001];
int accu[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> arr[0];
    accu[0] = arr[0];
    for (int i = 1; i < N; i++){
        cin >> arr[i];
        accu[i] = accu[i-1] + arr[i];
    }

    for (int i = 1; i < N - 1; i++){
        ans = max(ans, accu[N-1] - accu[i] + accu[N-1] - arr[i] - arr[0]);
    }
    for (int i = N - 2; i > 0; i--){
        ans = max(ans, accu[N-1] - arr[N-1] - arr[i] + accu[i-1]);
    }
    for (int i = 1; i < N - 1; i++){
        ans = max(ans, accu[i] - arr[0] + accu[N-2] - accu[i-1]);
    }
    cout << ans;

}