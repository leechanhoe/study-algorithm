#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;

    cin >> str;
    int len = str.size();
    int ans = len;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            if(str[j] != str[len-j+i-1]){
                ans++;
                break;
            }
            if(j == len - 1){
                cout << ans;
                return 0;
            }
        }
    }
}