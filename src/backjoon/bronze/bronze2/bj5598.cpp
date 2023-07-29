#include <iostream>
using namespace std;

string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        cout << static_cast<char>(s[i] + ('D' <= s[i] ? -3 : 23));
    }
    return 0;
}