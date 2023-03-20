#include <map>
#include <iostream>
using namespace std;

int N;
char game;
map<string, bool> m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> game;

    while(N--){
        string str;
        cin >> str;
        if(m.find(str) == m.end())
            m[str] = true;
    }

    if(game == 'Y')
        cout << m.size();
    else if(game == 'F')
        cout << m.size() / 2;
    else
        cout << m.size() / 3;
    return 0;
}