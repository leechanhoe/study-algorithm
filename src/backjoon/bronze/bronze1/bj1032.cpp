#include <iostream>
#include <string>
using namespace std;

string str[51];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> str[i];
    }
    int len = str[0].length();

    if(N != 1){
        for(int i = 0; i < len; i++){
            for(int j = 0; j < N; j++){
                if(str[0][i] != str[j][i]){
                    str[0][i] = '?';
                    break;
                }
            }
        }
    }
    cout << str[0];
}