#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int p, m;
int level;
string name;
map<string, int> dic;
vector<pair<int, vector<string>>> room;

int main(){
    cin >> p >> m;
    cin >> level >> name;
    
    room.push_back({level, {name}});
    dic[name] = level;
    for(int i = 1; i < p; i++){
        bool enter = false;
        cin >> level >> name;
        dic[name] = level;
        for(auto &r : room){
            if(abs(r.first - level) <= 10 && r.second.size() < m){
                r.second.push_back(name);
                enter = true;
                break;
            }
        }

        if(!enter)
            room.push_back({level, {name}});
    }

    for(auto &r : room){
        cout << (r.second.size() == m ? "Started!\n" : "Waiting!\n");
        sort(r.second.begin(), r.second.end());
        for(auto &n : r.second)
            cout << dic[n] << ' ' << n << '\n';
    }
    return 0;
}