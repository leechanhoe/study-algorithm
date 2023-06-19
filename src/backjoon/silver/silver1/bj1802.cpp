#include <iostream>
using namespace std;

bool dq(string io){
    int len = io.size();
    if(len == 1)
        return true;

    for(int i = 0; i < len / 2; i++){
        if(io[i] == io[len-i-1])
            return false;
    }
    
    return dq(io.substr(0, len / 2));
}

int T;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        string io;
        cin >> io;
        cout << (dq(io) ? "YES" : "NO") << '\n';
    }
    return 0;
}