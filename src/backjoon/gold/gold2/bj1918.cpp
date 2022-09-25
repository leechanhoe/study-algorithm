#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    stack<char> op;

    cin >> input;

    for (int i = 0; i < input.length(); i++){
        if('A' <= input[i] && input[i] <= 'Z'){
            cout << input[i];
        }
        else if(input[i] == '+' || input[i] == '-'){
            while(!op.empty() && op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.push(input[i]);
        }
        else if(input[i] == '*' || input[i] == '/'){
            while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                cout << op.top();
                op.pop();
            }
            op.push(input[i]);
        }
        else if(input[i] == '('){
            op.push(input[i]);
        }
        else if(input[i] == ')'){
            while (!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
            }
            op.pop();
        }
    }
    while (!op.empty()){
        cout << op.top();
        op.pop();
    }
}