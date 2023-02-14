#include <iostream>
#include <stack>
using namespace std;

int N, ans;
stack<int> stk;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        
        while(!stk.empty() && stk.top() >= y){
            if(stk.top() > y)
                ans++;
            stk.pop();
        }
        if(y > 0)
            stk.push(y);
    }

    ans += stk.size();
    cout << ans;
    return 0;
}