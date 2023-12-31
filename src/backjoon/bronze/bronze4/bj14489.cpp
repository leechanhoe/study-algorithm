#include <iostream>
using namespace std;

int a, b, c;

int main(){
    cin >> a >> b >> c;
    if(a + b >= 2 * c){
        cout << a + b - 2 * c;
    }
    else{
        cout << a + b;
    }
    return 0;
}