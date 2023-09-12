#include <iostream>
#include <deque>
using namespace std;

int T;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;
    while(T--){
        int N;
        char a;
        deque<char> dq;
        
        cin >> N;
        cin >> a;
        dq.push_back(a);
        for(int i = 1; i < N; i++){
            cin >> a;
            if(a <= dq.back()){
                dq.push_back(a);
            }
            else{
                dq.push_front(a);
            }
        }

        while(!dq.empty()){
            cout << dq.back();
            dq.pop_back();
        }
        cout << '\n';
    }
    return 0;
}