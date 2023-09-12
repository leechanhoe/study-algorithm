#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ho[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ho[i];
    }

    sort(ho, ho + N);

    int ans = 0;
    for(int i = N - 1; i > (N - 1) / 2; i--){
        ans += ho[i] * 2;
    }
    if(N % 2 == 1)
        ans += ho[N/2];
    
    cout << ans;
    return 0;
}