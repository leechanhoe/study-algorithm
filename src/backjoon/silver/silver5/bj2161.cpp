#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        dq.push_front(i);
    }
    
    while(!dq.empty()){
        cout << dq.back() << ' ';
        dq.pop_back();

        if(dq.empty())
            break;

        dq.push_front(dq.back());
        dq.pop_back();
    }
    return 0;
}