#include <bits/stdc++.h>
using namespace std;

char express[20];
int dep;

int calculate() {
    int ans = 0;
    int cur = 0;
    char op = '+';
    for(int i = 0; i <= dep; i++){
        if (express[i] == '-' || express[i] == '+' || express[i] == '\0'){
            if(op == '+'){
                ans += cur;
                cur = 0;
            }
            else if(op == '-'){
                ans -= cur;
                cur = 0;
            }
            op = express[i];
        }
        else if(express[i] == ' '){
            cur *= 10;
        }
        else{
            cur += express[i] - '0';
        }
    }
    return ans;
}

void dfs(int cur, int end){

    if(cur == end){
        express[dep++] = cur + '0';
        // for(int i = 0; i <= dep; i++){
        //     cout << express[i] << ' ';
        // }
        if(calculate() == 0){
            for(int i = 0; express[i] != '\0'; i++){
                cout << express[i];
            }
            cout << '\n';
        }
        dep--;
    }
    else{
        char ex[] = {' ', '+', '-'};
        for(char ch : ex){
            express[dep++] = cur + '0';
            express[dep++] = ch;
            dfs(cur + 1, end);
            dep -= 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        dfs(1, N);
        cout << '\n';
    }
}