#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    stack<char> stk;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            stk.push(str[i]);
        else{
            stk.pop();
            if(str[i-1] == '(')
                ans += stk.size();
            else
                ans++;
        }
    }
    cout << ans;
}