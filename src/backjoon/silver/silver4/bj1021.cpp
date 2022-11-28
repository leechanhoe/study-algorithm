#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N, M, ans = 0;
    deque<int> dq;

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        dq.push_back(i);

    while(M--){
        int a, idx;
        cin >> a;

        for(int i = 0; i < dq.size(); i++){
            if(dq[i] == a){
                idx = i;
                break;
            }
        }

        if(idx < dq.size() - idx){
            while(1){
                if(dq.front() == a){
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            while(1){
                if(dq.front() == a){
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << ans;
    return 0;
}