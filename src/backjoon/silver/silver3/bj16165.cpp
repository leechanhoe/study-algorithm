#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, vector<string>> m;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while(N--){
        string team, member;
        int num;
        cin >> team >> num;
        m[team] = vector<string>();

        while(num--){
            cin >> member;
            m[team].push_back(member);
        }
    }

    while(M--){
        int type;
        string s;
        cin >> s >> type;
        if(type == 0){
            sort(m[s].begin(), m[s].end());
            for(auto member : m[s]){
                cout << member << '\n';
            }
        }
        else{
            bool find = false;
            for(auto team : m){
                for(auto member : m[team.first]){
                    if(member == s){
                        cout << team.first << '\n';
                        break;
                    }
                }
                if(find)
                    break;
            }
        }
    }
    return 0;
}