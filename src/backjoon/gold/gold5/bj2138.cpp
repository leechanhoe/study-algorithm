#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int N, ans = MAX, cnt = 0;
string st, dt, tmp;

void switchOn(int i){
    if(i > 0)
        tmp[i-1] = tmp[i-1] == '0' ? '1' : '0';
    tmp[i] = tmp[i] == '0' ? '1' : '0';
    if(i < N - 1)
        tmp[i+1] = tmp[i+1] == '0' ? '1' : '0';
}

void solve(int first){
    tmp = st;
    cnt = 0;
    if(first == 0){ // 스위치를 눌렀을 때 첫번째 전구
        tmp[0] = tmp[0] == '0' ? '1' : '0';
        tmp[1] = tmp[1] == '0' ? '1' : '0';
        cnt++;
    }

    for(int i = 0; i < N; i++){
        if(tmp[i-1] != dt[i-1]){
            switchOn(i);
            cnt++;
        }
    }
    if (tmp == dt)
        ans = min(ans, cnt);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    cin >> st;
    cin >> dt;

    solve(0);
    solve(1);
    
    if(ans != MAX)
        cout << ans;
    else
        cout << -1;
}