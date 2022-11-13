#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(1){
        string str;
        getline(cin, str);

        if(str == "END")
            break;

        for(int i = str.size() - 1; i >= 0; i--)
            cout << str[i];

        cout << '\n';
    }
    return 0;
}