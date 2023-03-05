#include <iostream>
#include <stack>
using namespace std;

string str;

int main(){
    cin >> str;

    stack<char> stk;
    int ans = 0;
    int tmp = 1;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            tmp *= 2;
            stk.push(str[i]);
        }
        else if(str[i] == '['){
            tmp *= 3;
            stk.push(str[i]);
        }
        else if(str[i] == ')'){
            if(stk.empty() || stk.top() != '('){
                ans = 0;
                break;
            }
            if(str[i-1] == '('){
                ans += tmp;
            }
            tmp /= 2;
            stk.pop();
        }
        else if(str[i] == ']'){
            if(stk.empty() || stk.top() != '['){
                ans = 0;
                break;
            }
            if(str[i-1] == '['){
                ans += tmp;
            }
            tmp /= 3;
            stk.pop();
        }
    }
    if(!stk.empty()){
        ans = 0;
    }
    cout << ans;
    return 0;
}