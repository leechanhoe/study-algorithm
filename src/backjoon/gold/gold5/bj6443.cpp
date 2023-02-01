#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len;

void dfs(string s, int idx){
    if(idx == len - 1){
        cout << s << '\n';
        return;
    }

    for(int i = idx; i < len; i++){
        if(i != idx && s[i] == s[idx]){
            continue;
        }

        if(s[i] != s[idx]){
            char ch = s[i];
            s[i] = s[idx];
            s[idx] = ch;
        }
        dfs(s, idx + 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    while(N--){
        cin >> str;
        len = str.size();
        sort(str.begin(), str.end());
        dfs(str, 0);
    }
    return 0;
}