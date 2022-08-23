#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
using namespace std;

string str;

int main(){
    while(1){
        getline(cin, str);
        stack<char> stk;
        if (str[0] == '.')
            break;

        for (int i = 0; i < str.length() - 1; i++){
            if (str[i] == '(' || str[i] == '[')
                stk.push(str[i]);

            else if(str[i] == ']') {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else{
                    printf("no\n");
                    break;
                }
            }
            else if(str[i] == ')') {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else{
                    printf("no\n");
                    break;
                }
            }
            if (stk.empty() && i == str.length() - 2) 
                printf("yes\n");
			else if (!stk.empty() && i == str.length() - 2) 
                printf("no\n");
        }
    }
}