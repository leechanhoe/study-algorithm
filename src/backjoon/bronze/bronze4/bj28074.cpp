#include <iostream>
using namespace std;

string str;
bool alpha[26];

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        alpha[str[i]-'A'] = true;
    }

    if(alpha['M'-'A'] && alpha['O'-'A'] && alpha['B'-'A'] && alpha['I'-'A'] && alpha['S'-'A'])
        cout << "YES";
    else
        cout << "NO";
}