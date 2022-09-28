#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[1000001], cnt[1000001], ans[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    stack<int> stk;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for(int i = N - 1; i >= 0; i--){
        while(!stk.empty() && cnt[stk.top()] <= cnt[arr[i]]){
            stk.pop();
        }
        
        if(stk.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = stk.top();
        }
        stk.push(arr[i]);
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << ' ';
    }
}