#include <iostream>
#include <queue>
using namespace std;

int N, X;

int main(){
    cin >> N >> X;

    priority_queue<int> diff;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        ans += b;
        diff.push(a - b);
    }

    int cost = N * 1000;
    for(int i = 0; i < N; i++){    
        cost += 4000;
        if(X < cost || diff.top() <= 0)
            break;
        ans += diff.top();
        diff.pop();
    }

    cout << ans;
    return 0;
}