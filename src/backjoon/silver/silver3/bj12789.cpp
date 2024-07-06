#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int num;
int N;
int now = 1;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    while(N--){
        cin >> num;
        if (num == now){
            now++;
        }
        else{
            stk.push(num);
        }
        while (!stk.empty() && stk.top() == now){
            now++;
            stk.pop();
        }
    }
    
            
    if (stk.empty()){
        cout << "Nice";
    }
    else{
        cout << "Sad";
    }
    return 0;
}