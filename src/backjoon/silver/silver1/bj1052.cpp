#include <iostream>
using namespace std;

int N, K;

int main(){
    cin >> N >> K;

    if(N < K){
        cout << 0;
        return 0;
    }

    int ans = 0;
    while(1){
        int tmp = N;
        int one = 0;
        while(tmp > 0){
            if(tmp % 2 == 1)
                one++;
            tmp /= 2;
        }
        if(one <= K)
            break;
        N++;
        ans++;
    }
    cout << ans;
    return 0;
}