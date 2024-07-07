#include <iostream>
using namespace std;

string S;
int q;
int cnt[26][200001];

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

    cin >> S;
    cin >> q;

    cnt[S[0]-'a'][0] = 1;
    for(char i = 'a'; i <= 'z'; i++){
        for(int j = 1; j < S.size(); j++){
            cnt[i-'a'][j] = cnt[i-'a'][j-1] + (S[j] == i ? 1 : 0);
        }
    }

    while(q--){
        char a;
        int l, r;
        cin >> a >> l >> r;
        cout << (cnt[a-'a'][r] - (l == 0 ? 0 : cnt[a-'a'][l-1])) << '\n';
    }
    
    return 0;
}