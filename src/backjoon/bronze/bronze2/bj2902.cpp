#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
 
    vector<char> ans;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-'){
            ans.push_back(str[i+1]);
        }
    }

    cout << str[0];
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
}
