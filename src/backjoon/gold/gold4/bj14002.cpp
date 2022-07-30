#include <iostream>
#include <vector>
using namespace std;

int N, arr[1001], len;
int maxIndex, tmp;
int dp[1001];
vector<int> v;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        len = 0;

        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i])
                len = max(len, dp[j]);
        }
        dp[i] = len + 1;

        if(tmp < len + 1){
            tmp = len + 1;
            maxIndex = i;
        }
    }

    for(int i = maxIndex; i >= 0; i--){
        if(dp[i] == tmp){
            v.push_back(arr[i]);
            tmp--;
        }
    }
    int size = v.size();
    cout << size << '\n';
    for(int i = 0; i < size; i++){
        cout << v.back() << ' ';
        v.pop_back();
    }
}