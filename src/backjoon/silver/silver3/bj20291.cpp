#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N;
map<string, int> ex;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        s.erase(0, s.find('.') + 1);
        if(ex.find(s) == ex.end())
            ex[s] = 1;
        else
            ex[s]++;
    }
    for(auto e : ex){
        cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}