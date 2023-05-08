#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
char cmd, x;
int M, cs;
stack<char> le;
stack<char> ri;

int main(){
    cin >> str >> M;

    for(int i = 0; i < str.size(); i++)
        le.push(str[i]);

    for(int i = 0; i < M; i++){
        cin >> cmd;
        switch (cmd)
        {
        case 'L':
            if(!le.empty()){
                ri.push(le.top());
                le.pop();
            }
            break;
        case 'D':
            if(!ri.empty()){
                le.push(ri.top());
                ri.pop();
            }
            break;
        case 'B':
            if(!le.empty()){
                le.pop();
            }
            break;
        case 'P':
            cin >> x;
            le.push(x);
            break;
        }
    }
    while (!le.empty())
    {
        ri.push(le.top());
        le.pop();
    }

    while (!ri.empty())
    {
        cout << ri.top();
        ri.pop();
    }
    return 0;
}