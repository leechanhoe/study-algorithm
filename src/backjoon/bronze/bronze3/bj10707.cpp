#include <iostream>
using namespace std;

int a, b, c, d, p, x, y;

int main(){
    cin >> a >> b >> c >> d >> p;
    x = a * p;

    if(p <= c){
        y = b;
    }
    else{
        y = b + (p - c) * d;
    }

    cout << min(x, y);
    return 0;
}