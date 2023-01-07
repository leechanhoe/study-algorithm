#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nums[2];
bool dp[600001][3];
int N, x, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        int xx = x + 300000;
        if(dp[xx][2])
            ans++;

        if(!dp[xx][0]){
            nums[0].push_back(x);
            dp[xx][0] = true;
        }

        for(int n : nums[0]){
            xx = n + x + 300000;
            if(!dp[xx][1]){
                nums[1].push_back(x+n);
                dp[xx][1] = true;
            }
        }

        for(int n : nums[1]){
            xx = n + x + 300000;
            dp[xx][2] = true;
        }
    }
    cout << ans;
    return 0;
}