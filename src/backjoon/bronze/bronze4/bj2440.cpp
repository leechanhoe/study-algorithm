#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        for(int i = 0; i <= N; i++){
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}