#include <iostream>
using namespace std;

int main(){
    string input;
    int zero = 0, one = 0, len;

    cin >> input;
    if(input[0] == '0')
        zero++;
    else
        one++;

    len = input.size();
    for(int i = 1; i < len; i++){
        if(input[i] != input[i-1]){
            if(input[i] == '0')
                zero++;
            else
                one++;
        }
    }
    cout << min(zero, one);
}