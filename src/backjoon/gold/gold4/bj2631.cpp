#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[201];
int arr[201];
vector<int> lis;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    lis.push_back(arr[0]);
    for (int i = 1; i < N; i++){
        if (lis.back() < arr[i])
            lis.push_back(arr[i]);
        else{
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    cout << N - lis.size();
}