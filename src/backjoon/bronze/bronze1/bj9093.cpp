#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--){
        string str = "";
        getline(cin, str);
        stack<char> stk;
        str += ' ';
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                while(!stk.empty()){
                    cout << stk.top();
                    stk.pop();
                }
                cout << str[i];
            }
            else{
                stk.push(str[i]);
            }
        }
        cout << '\n';
    }
}