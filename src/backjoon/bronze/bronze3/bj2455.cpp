#include <iostream>
using namespace std;

int main(){
    int a, b, ans = 0, now = 0;

    for(int i = 0; i < 4; i++){
        cin >> a >> b;
        now -= a;
        now += b;
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}