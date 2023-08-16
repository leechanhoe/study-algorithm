#include <iostream>
#include <queue>
using namespace std;

int n, w, L;
int truck[1001];
queue<pair<int, int>> q;
int now, noww, ans;

int main(){
    cin >> n >> w >> L;
    for(int i = 0; i < n; i++){
        cin >> truck[i];
    }

    int pass = 0;
    int idx = 0;
    while(1){
        if(!q.empty() && now - q.front().second == w){
            noww -= truck[q.front().first];
            q.pop();
            pass++;
        }

        if(idx < n && noww + truck[idx] <= L){
            noww += truck[idx];
            q.push({idx, now});
            idx++;
        }

        now++;
        if(pass == n)
            break;
    }

    cout << now;
    return 0;
}