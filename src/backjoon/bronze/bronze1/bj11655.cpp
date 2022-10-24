#include<iostream>
#include<string>
using namespace std;

string s;
int tmp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    getline(cin, s);

    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' ')
            cout << ' ';
        else if (s[i] >= 'a' && s[i] <= 'z'){
            tmp = (s[i] - 'a' + 13) % 26;
            cout << char('a' + tmp);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z'){
            tmp = (s[i] - 'A' + 13) % 26;
            cout << char('A' + tmp);
        }
        else cout << s[i];
    }
}