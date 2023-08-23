#include <iostream>
using namespace std;
typedef long long ll;

int N;
ll X;
ll burger[51];
ll patty[51];
ll ans;

void solve(int l, ll low){
    if(low == 0){
        cout << ans;
        return;
    }
    else if(l == 0){
        ans++;
        cout << ans;
        return;
    }

    low--;
    if(low == burger[l-1]){
        ans += patty[l-1];
        low -= burger[l-1];
        solve(l-1, low);
    }
    else if(low < burger[l-1]){
        solve(l-1, low);
    }
    else if(low > burger[l-1]){
        ans += patty[l-1] + 1;
        low -= burger[l-1] + 1;
        solve(l-1, low);
    }
}

int main(){
    cin >> N >> X;

    burger[0] = 1;
    patty[0] = 1;
    for(int i = 1; i <= 50; i++){
        burger[i] = burger[i-1] * 2 + 3;
        patty[i] = patty[i-1] * 2 + 1;
    }
    solve(N, X);
    return 0;
}
