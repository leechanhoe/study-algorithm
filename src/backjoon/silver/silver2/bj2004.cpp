#include <iostream>
#define ll long long
using namespace std;

pair<ll, ll> count(ll n){
    ll two = 0;
    ll five = 0;

    for(ll i = 2; i <= n; i *= 2){
        two += n / i;
    }

    for(ll i = 5; i <= n; i *= 5){
        five += n / i;
    }
    return make_pair(two, five);
}

int main(){
    ll N, M;
    cin >> N >> M;

    pair<ll, ll> n = count(N);
    pair<ll, ll> nm = count(N - M);
    pair<ll, ll> m = count(M);
    ll a = n.first - (nm.first + m.first);
    ll b = n.second - (nm.second + m.second);

    cout << (a < b ? a : b);
}