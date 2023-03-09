#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, T;
int log[10001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> log[i]; 
        }

        sort(log, log + N, greater<int>());
        deque<int> dq;
        for(int i = 0; i < N; i++){
            if(i & 1)
                dq.push_back(log[i]);
            else
                dq.push_front(log[i]);
        }

        int maxDiff = abs(dq.front() - dq.back());
        int now = dq.front();
        dq.pop_front();
        for(int i = 1; i < N; i++){
            maxDiff = max(maxDiff, abs(now - dq.front()));
            now = dq.front();
            dq.pop_front();
        }
        cout << maxDiff << '\n';
    }
}