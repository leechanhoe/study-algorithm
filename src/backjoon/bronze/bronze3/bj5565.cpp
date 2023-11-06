#include <iostream>
using namespace std;

int main(){
    int sum;
    cin >> sum;
    for(int i = 0, book; i < 9; i++){
        cin >> book;
        sum -= book;
    }
    cout << sum;
}