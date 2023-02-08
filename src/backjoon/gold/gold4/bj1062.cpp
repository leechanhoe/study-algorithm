#include <iostream>
#include <string>
using namespace std;

int N, K, ans;
string word[51];
bool alpha[26];

int canRead(){
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        bool read = true;
        for(int j = 0; j < word[i].length(); j++){

            if(!alpha[word[i][j] - 'a']){
                read = false;
                break;
            }
        }

        if(read){
            cnt++;
        }
    }
    return cnt;
}

void dfs(int idx, int abc){
    if(abc == K){
        ans = max(ans, canRead());
        return;
    }

    for(int i = idx; i < 26; i++){
        if(alpha[i])
            continue;
        alpha[i] = true;
        dfs(i, abc + 1);
        alpha[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> word[i];
    }
    if(K < 5){
        cout << 0;
        return 0;
    }

    alpha['a'-'a'] = alpha['c'-'a'] = alpha['t'-'a'] = alpha['i'-'a'] = alpha['n'-'a'] = true;
    K -= 5;
    dfs(0, 0);
    cout << ans;
    return 0;
}