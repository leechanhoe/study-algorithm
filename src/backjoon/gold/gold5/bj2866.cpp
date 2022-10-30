#include <iostream>
#include <vector>
#include <set>
using namespace std;

int R, C, ans;
string str[1001][1001];
vector<string> col;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string input;
        cin >> input;
        for(int j = 0; j < C; j++){
            str[i][j] = input[j];
        }
    }

    for(int i = 0; i < C; i++){
        string s = "";
        for(int j = 1; j < R; j++){
            s += str[j][i];
        }
        col.push_back(s);
    }

    for(int i = 0; i < R - 1; i ++){
        set<string> se;
        bool overlap = false;
        for(int j = 0; j < col.size(); j++){
            if(se.find(col[j]) == se.end()){
                se.insert(col[j]);
            }
            else{
                overlap = true;
                break;
            }
        }
        
        if(overlap){
            break;
        }
        else{
            for(int j = 0; j < col.size(); j++){
                col[j].erase(col[j].begin());
            }
            ans++;
        }
    }
    cout << ans;
}