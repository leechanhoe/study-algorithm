#include <iostream>
#include <map>
using namespace std;

int N;
map<string, int> name;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(name.find(s) == name.end())
            name[s] = 1;
        else
            name[s]++;
    }

    for(int i = 0; i < N - 1; i++){
        string s;
        cin >> s;
        name[s]--;
    }

    for(auto s : name){
        if(0 < s.second){
            cout << s.first;
            return 0;
        }
    }
}