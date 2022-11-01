#include <iostream>
#include <string>
using namespace std;

bool chk[101];
string str;

void f(int le, int ri){
    int mini = 199, idx = -1;
    for(int i = le; i < ri + 1; i++){
        if(!chk[i] && mini > str[i]){
            mini = str[i];
            idx = i;
        }
    }

    if(mini == 199)
        return;
    chk[idx] = true;
    for(int i = 0; str[i]; i++){
        if(chk[i]){
            cout << str[i];
        }
    }
    cout << '\n';
    f(idx + 1, ri);
    f(le, idx - 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    f(0, str.length() - 1);
    return 0;
}