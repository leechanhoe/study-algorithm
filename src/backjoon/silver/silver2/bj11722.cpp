#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
    }

    cout << *max_element(dp, dp + N);
    return 0;
}