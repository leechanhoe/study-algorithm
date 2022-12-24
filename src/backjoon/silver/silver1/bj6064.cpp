#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, M, N, x, y, i;
    cin >> T;
    
    while(T--){
        cin >> M >> N >> x >> y;
        int lim = lcm(M, N);
        for(i = x; i <= lim; i += M){
            int tmp = i % N == 0 ? N : i % N; // 0 방지
            if(tmp == y){
                cout << i << '\n';
                break;
            }
        }
        if(i > lim)
            cout << -1 << '\n';
    }
    return 0;
}