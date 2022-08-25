#include <iostream>
using namespace std;

int ans, N, pi[5001];
char str[5001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    for (int i = 0; str[i] != '\0'; i++){
        int k = 0; // pi만들때 어차피 문자열 전체를 검사하므로 자연스럽게 n**2 전체 문자열이 탐색됨
        for (int j = i + 1; str[j] != '\0'; j++){ 
            while(k > 0 && str[j] != str[i+k])
                k = pi[k-1];
            if(str[i+k] == str[j]){
                ans = max(ans, ++k);
            }
            pi[j - i] = k;
        }
    }
    cout << ans;
}