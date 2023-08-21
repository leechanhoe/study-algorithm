#include <iostream>
using namespace std;

string s1, s2;
int abc[26];

int main(){
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++){
        abc[s1[i]-'a']++;
    }

    for(int i = 0; i < s2.size(); i++){
        abc[s2[i]-'a']--;
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans += abs(abc[i]);
    }

    cout << ans;
    return 0;
}