#include <iostream>
using namespace std;

string a, b;
long long ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++){
        a[i] -= '0';
    }
    for(int i = 0; i < b.size(); i++){
        b[i] -= '0';
    }

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            ans += a[i] * b[j];
        }
    }
    cout << ans;
}