#include <iostream>
#include <map>
using namespace std;

long long N, ans, ma;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    map<long long, long long> m;
    while(N--){
        long long card;
        cin >> card;
        if(m.find(card) == m.end()){
            m[card] = 1;
        }
        else{
            m[card]++;
        }
    }

    for(auto a : m){
        if(ma < a.second){
            ans = a.first;
            ma = a.second;
        }
    }
    cout << ans;
    return 0;
}