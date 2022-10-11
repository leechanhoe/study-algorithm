#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin>>str;
 
    int len = str.length();
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len-1-i]){
            cout << "0" << "\n";
            return 0;
        }
    }
    cout << "1" << "\n";
}