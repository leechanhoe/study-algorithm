#include <iostream>
using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        int a, b;
        string str;
        cin >> a >> b >> str;
        for(int i = 0; i < str.size(); i++){
            cout << (char)(((str[i] - 'A') * a + b) % 26 + 'A');
        }
        cout << '\n';
    }
    return 0;
}