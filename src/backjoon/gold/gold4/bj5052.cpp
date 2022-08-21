#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    int t; cin >> t;
    for(int tc = 1; tc<=t; tc++){
        int N; cin >> N;
        string str;
        vector<string> vec;

        for(int i = 0; i < N; i++){
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());

        bool flag = true;
        for(int i = 0; i < vec.size()-1; i++){
            
            string cur = vec[i];
            string next = vec[i+1];
            flag = true;
            if(cur.length() > next.length()) continue;
            if(cur == next.substr(0, cur.length())){
                flag = false;
                break;
            }
        }
        if(!flag) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}