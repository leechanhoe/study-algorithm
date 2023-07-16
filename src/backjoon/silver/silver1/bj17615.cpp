#include <iostream>
using namespace std;

int N, ans;
string ball;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> ball;

    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(!flag && ball[i] == 'B')
            flag = true;
        else if(flag && ball[i] == 'R')
            cnt++;
    }
    ans = cnt;

    cnt = 0;
    flag = false;
    for(int i = 0; i < N; i++){
        if(!flag && ball[i] == 'R')
            flag = true;
        else if(flag && ball[i] == 'B')
            cnt++;
    }
    ans = min(ans, cnt);

    cnt = 0;
    flag = false;
    for(int i = N - 1; i >= 0; i--){
        if(!flag && ball[i] == 'R')
            flag = true;
        else if(flag && ball[i] == 'B')
            cnt++;
    }
    ans = min(ans, cnt);

    cnt = 0;
    flag = false;
    for(int i = N - 1; i >= 0; i--){
        if(!flag && ball[i] == 'B')
            flag = true;
        else if(flag && ball[i] == 'R')
            cnt++;
    }
    ans = min(ans, cnt);
    cout << ans;
}