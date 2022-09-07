#include <bits/stdc++.h>
using namespace std;

int arrow[1000001];
int N, ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        int balloon;
        cin >> balloon;
        if (!arrow[balloon]){
            ans++;
            arrow[balloon-1]++;
        }
        else{
            arrow[balloon]--;
            arrow[balloon-1]++;
        }
    }
    cout << ans;
}