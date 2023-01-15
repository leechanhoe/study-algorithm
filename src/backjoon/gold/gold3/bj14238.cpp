#include <iostream>
#include <string>
using namespace std;

bool dp[51][51][51][3][2];
string str;

string dfs(int a, int b, int c, int bx, int cx){
    if(bx > 0)
        bx--;
    if(cx > 0)
        cx--;

    if(dp[a][b][c][bx][cx])
        return "";
    dp[a][b][c][bx][cx] = true;
    if(a == 0 && b == 0 && c == 0)
        return "O";

    string ret;    
    if(a > 0){
        ret = dfs(a-1, b, c, bx, cx);
        if(ret[ret.size()-1] == 'O')
            return 'A' + ret;
    }
    if(b > 0 && bx == 0){
        ret = dfs(a, b-1, c, 2, cx);
        if(ret[ret.size()-1] == 'O')
            return 'B' + ret;
    }
    if(c > 0 && cx == 0){
        ret = dfs(a, b, c-1, bx, 3);
        if(ret[ret.size()-1] == 'O')
            return 'C' + ret;
    }
    return "";
}

int main(){
    cin >> str;

    int a = 0, b = 0, c = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'A')
            a++;
        else if(str[i] == 'B')
            b++;
        else if(str[i] == 'C')
            c++;
    }
    string ans = dfs(a, b, c, 0, 0);
    if(ans[ans.size()-1] == 'O')
        cout << ans.substr(0, ans.size()-1);
    else{
        cout << -1;
    }
    return 0;
}