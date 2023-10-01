#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, less<int>> pq;

int main(){
    cin >> n;

    while(n--){
        int a;
        cin >> a;
        if(!a){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }

        for(int i = 0; i < a; i++){
            int gift;
            cin >> gift;
            pq.push(gift);
        }
    }

    return 0;
}