#include <iostream>
using namespace std;

int main(){
    int X, ans = 0;
    cin >> X;

    while(X > 0){
        if(X % 2 == 1)
            ans++;
        X /= 2;
    }
    cout << ans;
    return 0;
}