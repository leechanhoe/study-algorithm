#include <iostream>
#include <stack>
using namespace std;

int N, h, dup;
long long ans;
stack<pair<int, int>> stk;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h;
        dup = 1;

        while(!stk.empty() && stk.top().first < h){
            ans += stk.top().second;
            stk.pop();
        }

        if(!stk.empty()){
            if(stk.top().first == h){
                ans += stk.top().second; // 같은건 서로 바라볼 수 있으니
                dup = stk.top().second + 1;

                if(stk.size() > 1) // 앞에 이미 큰 사람이 한명이상 있으면 서로 바라볼 수 있으니
                    ans++;

                stk.pop(); // 중복되는것 제거
            }
            else{
                ans++;
            }
        }
        stk.push({h, dup});
    }
    cout << ans;
    return 0;
}