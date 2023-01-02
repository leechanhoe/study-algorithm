#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, bal;
    deque<pair<int, int>> dq;

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> bal;
        dq.push_back({i, bal});
    }

    while(1){
        int val = dq.front().second;
        cout << dq.front().first << ' ';
        dq.pop_front();
        if(dq.empty())
            break;
        
        if(val > 0){
            for(int i = 0; i < val - 1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i = val; i < 0; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}