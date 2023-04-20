#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1){
        string s;
        int ans = 0;

        getline(cin, s);
        if(s == "#")
            break;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}