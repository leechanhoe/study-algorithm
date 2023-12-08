#include <iostream>
#include <cstring>
using namespace std;

int T;
bool abc[26];

int main(){
    cin >> T;
    
    while(T--){
        memset(abc, false, sizeof(abc));
        int ans = 0;
        string str;

        cin >> str;
        for(int i = 0; i < str.size(); i++){
            abc[str[i]-'A'] = true;
        }
        for(int i = 0; i < 26; i++){
            if(!abc[i]){
                ans += i + 'A';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}