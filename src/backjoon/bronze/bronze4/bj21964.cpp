#include <iostream>
using namespace std;

int N;
string str;

int main(){
    cin >> N >> str;
    for(int i = N - 5; i < N; i++){
        cout << str[i];
    }
    return 0;
}