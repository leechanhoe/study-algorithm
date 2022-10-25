#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, words[101];
    int N, dp[101];
    
    cin >> s >> N;
    for(int i = 0; i < N; i++){
        cin >> words[i];
    }

    dp[s.size()] = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        for(int j = 0; j <= N; j++){
            if(s.find(words[j], i) == i && dp[i + words[j].size()] == 1){
                dp[i] = 1;
                break;
            }
            else{
                dp[i] = 0;
            }
        }
    }
    cout << dp[0];
}