#include <iostream>
using namespace std;

int main(){
    string s;
    int N, ans = 0;

    cin >> N >> s;

    for(int i = 0; i < N; i++){
        ans++;
        if(s[i] == 'L')
            i++;
    }
    cout << min(N, ans + 1);
    return 0;
}