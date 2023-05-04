#include <bits/stdc++.h>
using namespace std;

int N, ans;
string s, ring;

int main(){
    cin >> s;
    cin >> N;

    while(N--){
        cin >> ring;
        ring += ring;
        if(ring.find(s) != string::npos)
            ans++;
    }
    cout << ans;
    return 0;
}