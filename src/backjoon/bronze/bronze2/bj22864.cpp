#include <iostream>
using namespace std;

int A, B, C, M;
int ans, now;

int main(){
    cin >> A >> B >> C >> M;

    for(int i = 0; i < 24; i++){
        if(now + A <= M){
            now += A;
            ans += B;
        }
        else{
            now = max(0, now - C);
        }
    }
    cout << ans;
    return 0;
}