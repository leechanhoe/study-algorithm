#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, x;
string str;
queue<int> q;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        
        if(str == "push"){
            cin >> x;
            q.push(x);
        }
        else if(str == "pop"){
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(str == "size"){
            cout << q.size() << '\n';
        }
        else if(str == "empty"){
            cout << q.empty() << '\n';
        }
        else if(str == "front"){
            if(!q.empty()){
                cout << q.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else{
            if(!q.empty()){
                cout << q.back() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}