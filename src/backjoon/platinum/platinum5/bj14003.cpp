#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int *arr = new int[N];
    int *dp = new int[N];
    int idx, tmp = 0;
    vector<int> lis;
    vector<int> ans;
    vector<int>::iterator p;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(lis.size() == 0){
            lis.push_back(arr[i]);
            dp[i] = 1;
        }
        else{
            if(lis.back() < arr[i]){
                lis.push_back(arr[i]);
                dp[i] = lis.size();
            }
            else{
                p = lower_bound(lis.begin(), lis.end(), arr[i]);
                *(p) = arr[i];
                dp[i] = p - lis.begin() + 1;
            }
        }
        if(dp[i] > tmp){
            tmp = dp[i];
            idx = i;
        }
    }
    ans.push_back(arr[idx]);
    for(int i = idx; i >= 0; i--){
        if(arr[i] < arr[idx] && dp[i] + 1 == dp[idx]){
            idx = i;
            ans.push_back(arr[i]);
        }
    }
    cout << lis.size() << '\n';
    while(!ans.empty()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }
}