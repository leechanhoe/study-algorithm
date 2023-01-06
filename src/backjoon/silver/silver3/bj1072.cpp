#include <iostream>
using namespace std;

long long X, Y, Z;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> X >> Y;
    Z = Y * 100 / X;
    if(Z >= 99){
        cout << -1;
        return 0;
    }

    int lo = 0;
    int hi = 1000000000;
    int mi, ans;
    while(lo <= hi){
        mi = (lo + hi) / 2;
        if(((Y + mi) * 100) / (X + mi) > Z){
            hi = mi - 1;
        }
        else{
            lo = mi + 1;
            ans = mi;
        }
    }
    cout << ans + 1;
    return 0;
}