#include <iostream>
using namespace std;

int N, name[26];

int main(){
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        name[s[0] - 'a']++;
    }

    bool enter = false;
    for(int i = 0; i < 26; i++){
        if(name[i] >= 5){
            cout << char('a' + i);
            enter = true;
        }
    }
    if(!enter)
        cout << "PREDAJA";

    return 0;
}