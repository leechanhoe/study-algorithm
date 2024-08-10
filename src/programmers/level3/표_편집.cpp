#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int up[1000001];
int down[1000001];
int now;
stack<int> del;

string solution(int n, int k, vector<string> cmd) {
    for(int i = 0; i < n; i++){
        up[i] = i - 1;
        down[i] = i + 1;
    }

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i][0] == 'U'){
            int x = stoi(cmd[i].substr(2));
            int now = k;
            for(int j = 0; j < x; j++){
                now = up[now];
            }
            k = now;
        }

        else if(cmd[i][0] == 'D'){
            int x = stoi(cmd[i].substr(2));
            int now = k;
            for(int j = 0; j < x; j++){
                now = down[now];
            }
            k = now;
        }
        
        else if(cmd[i][0] == 'C'){
            del.push(k);
            up[down[k]] = up[k];
            down[up[k]] = down[k];
            if (down[k] == n)
                k = up[k];
            else
                k = down[k];
        }
        
        else if(cmd[i][0] == 'Z'){
            int re = del.top();
            del.pop();
            up[down[re]] = re;
            down[up[re]] = re;
        }
    }
    
    string answer(n, 'O');
    while(!del.empty()){
        answer[del.top()] = 'X';
        del.pop();
    }
    return answer;
}