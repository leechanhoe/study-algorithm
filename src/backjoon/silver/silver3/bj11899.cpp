#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> stk;
int ans;

int main(){
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ')'){
            if(stk.empty()){
                ans++;
            }
            else{
                if(stk.top() == '(')
                    stk.pop();
                else
                    ans++;
            }
        }
        else{
            stk.push(str[i]);
        }
    }
    
    ans += stk.size();
    cout << ans;
    return 0;
}