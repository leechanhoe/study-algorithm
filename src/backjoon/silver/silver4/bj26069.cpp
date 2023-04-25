#include <iostream>
#include <map>
using namespace std;

int N;

int main(){
    cin >> N;

    map<string, bool> m;
    m["ChongChong"] = true;
    while(N--){
        string a, b;
        cin >> a >> b;
        if(m.find(a) == m.end())
            m[a] = false;
        if(m.find(b) == m.end())
            m[b] = false;

        if(m[a] || m[b]){
            m[a] = true;
            m[b] = true;
        }
    }

    int ans = 0;
    for(auto i : m){
        if(i.second)
            ans++;
    }
    cout << ans;
    return 0;
}