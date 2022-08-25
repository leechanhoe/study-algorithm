#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int pSize = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'P'){
            pSize++;
        }
        else{
            if(pSize >= 2 && s[i+1] == 'P'){
                pSize--;
                i++;
            }
            else{
                cout << "NP";
                return 0;
            }
        }
    }
    if(pSize == 1)
        cout << "PPAP";
    else
        cout << "NP";
}