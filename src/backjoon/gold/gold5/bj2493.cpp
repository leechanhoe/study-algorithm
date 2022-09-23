// #include <iostream>
// #include <stack>
// using namespace std;

// int N;
// int tower[500001];

// int main() {
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     stack<int> stk, ans;
//     cin >> N;
//     for (int i = 0; i < N; i++){
//         cin >> tower[i];
//     }
//     stk.push(tower[N-1]);
//     for (int i = N - 2; i >= 0; i--){
//         while(!stk.empty() && tower[i] >= stk.top()){
//             stk.pop();
//             ans.push(i+1);
//         }
//         stk.push(tower[i]);
//     }

//     while(ans.size() < N){
//         ans.push(0);
//     }

//     for (int i = 0; i < N; i++){
//         cout << ans.top() << ' ';
//         ans.pop();
//     }
// }

#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    stack<pair<int, int> > stk;  // pair<int, int> : index, height
    int N, height;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        cin >> height;
 
        while (!stk.empty()) {
            //수신탑 발견했을 때
            if (height < stk.top().second) {
                cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        //수신 탑이 없다면
        if (stk.empty()) {
            cout << 0 << " ";
        }
        //현재 높이를 스택에 푸쉬
        stk.push(make_pair(i + 1, height));
    }
}