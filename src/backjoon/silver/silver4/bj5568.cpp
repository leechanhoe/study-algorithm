#include <bits/stdc++.h>
using namespace std;

int n, k;
set<string> se;
bool visited[11];
string s[11];

void dfs(string str, int d){
    if(d == k){
        se.insert(str);
        return;
    }

    string origin = str;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            str += s[i];
            dfs(str, d+1);
            str = origin;
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    dfs("", 0);
    cout << se.size();
    return 0;
}