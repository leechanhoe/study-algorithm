#include <iostream>
using namespace std;

int N;
int stick[100001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> stick[i];
    }

    int ma = 0, ans = 0;
    for(int i = N - 1; i >= 0; i--){
        if(ma < stick[i]){
            ma = stick[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}