#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string S;
    cin >> S;

    string sub = S.substr(0, 1);
    for(int i = 1; i < S.length(); i++)
        sub = sub[i-1] < S[i] ? S[i] + sub : sub + S[i];

    reverse(sub.begin(), sub.end());
    cout << sub;
    return 0;
}