#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int T;
ll price[1000001];

int main(){
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> price[i];
        }

        ll ans = 0, high = price[N-1];
        for(int i = N-2; i >= 0; i--){
            if(high > price[i]){
                ans += high - price[i];
            }
            else{
                high = price[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}