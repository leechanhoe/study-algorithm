#include <iostream>
using namespace std;

bool visited[51];

int dfs(string& s, int i){
    int cnt = 0;

    for(int j = i; j < s.size(); j++){
        if(s[j] == '(' && !visited[j]){
            visited[j] = true;
            cnt += (s[j-1] - '0') * dfs(s, j + 1) - 1;
        }
        else if (s[j] == ')' && !visited[j]){
            visited[j] = true;
            return cnt;
        }
        else if(!visited[j]){
            visited[j] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string str;
    cin >> str;
    cout << dfs(str, 0);
}