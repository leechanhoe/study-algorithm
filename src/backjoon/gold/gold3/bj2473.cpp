#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int N;
long long arr[5001];
long long ans[3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);

    long long ansSum = 3987654321;
    for(int i = 0; i < N - 2; i++){
        int le = i + 1;
        int ri = N - 1;
        while(le < ri){
            long long sum = arr[i] + arr[le] + arr[ri];
            if(abs(sum) < ansSum){
                ansSum = abs(sum);
                ans[0] = arr[i];
                ans[1] = arr[le];
                ans[2] = arr[ri];
            }
            if(sum < 0){
                le++;
            }
            else{
                ri--;
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}