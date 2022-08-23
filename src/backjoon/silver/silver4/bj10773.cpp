#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K, n;
    cin >> K;
    stack<int> stk;
    for (int i = 0; i < K; i++) {
        cin >> n;
        if (n != 0) {
            stk.push(n);
        } else {
            stk.pop();
        }
    }

    int ans = 0;
    int len = stk.size();
    for (int i = 0; i < len; i++) {
        ans += stk.top();
        stk.pop();
    }
    cout << ans;
}