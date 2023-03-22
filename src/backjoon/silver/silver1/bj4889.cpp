#include <iostream>
#include <stack>
using namespace std;

int main(){
    int tc = 1;
    while(1){
        string s;
        cin >> s;
        if(s[0] == '-')
            break;
        
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(!stk.empty() && stk.top() == '{' && s[i] == '}')
                stk.pop();
            else
                stk.push(s[i]);
        }
        
        int leftNum = 0;
        int len = stk.size();
        for(int i = 0; i < len; i++){
            if(stk.top() == '}'){
                leftNum = i;
                break;
            }
            stk.pop();
        }

        if((len - leftNum) % 2 == 0){
            cout << tc << ". " << len / 2 << '\n';
        }
        else{
            cout << tc << ". " << len / 2 + 1 << '\n';
        }
        tc++;
    }
}