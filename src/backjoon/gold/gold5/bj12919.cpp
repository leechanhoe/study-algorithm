#include <iostream>
#include <algorithm>
using namespace std;

void f(string s, string t){
    if(s == t){
        cout << 1;
        exit(0);
    }

    if(s.size() >= t.size())
        return;

    string tmp;
    if(t[t.size()-1] == 'A'){
        tmp = t;
        tmp.erase(tmp.end()-1);
        f(s, tmp);
    }
    if(t[0] == 'B'){
        tmp = t;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        f(s, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string S, T;
    cin >> S >> T;
    f(S, T);
    cout << 0;
}