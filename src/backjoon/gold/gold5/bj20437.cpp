#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        string str; 
        int K; 
        cin >> str >> K;
        
        vector<int> cnt(26);
        for (int i = 0; i < str.length(); i++)
            ++cnt[str[i] - 'a'];
        
        int ans3 = INT_MAX; 
        int ans4 = -1;
        for (int i = 0; i < str.length(); ++i) {
            if (cnt[str[i] - 'a'] < K)
                continue;

            int cnt = 0;
            for (int j = i; j < str.length(); ++j) {
                if (str[i] == str[j])
                    ++cnt;
                
                if (cnt == K) { 
                    ans3 = min(ans3, j - i + 1);
                    ans4 = max(ans4, j - i + 1);
                    break;
                }
            }
        }
        
        if (ans3 == INT_MAX || ans4 == -1) 
            cout << -1 << "\n";
        else 
            cout << ans3 << " " << ans4 << "\n";
    }
}