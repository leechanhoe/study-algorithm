#include <iostream>
using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        int loc;
        string str;

        cin >> loc >> str;

        for(int i = 0; i < str.size(); i++){
            if(i + 1 == loc)
                continue;
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}