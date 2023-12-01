#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[10];
string str;
int main(){
    for(int i = 0; i < 3; i++){
        memset(cnt, 0, sizeof(cnt));
        cin >> str;

        char now = str[0];
        int same = 1;
        cnt[str[0] - '0'] = same;
        for(int j = 1; j < str.size(); j++){
            if(str[j] == str[j-1]){
                same++;
            }
            else{
                same = 1;
            }
            cnt[str[j] - '0'] = max(cnt[str[j] - '0'], same);
        }

        cout << *max_element(cnt, cnt + 10) << '\n';
    }
}