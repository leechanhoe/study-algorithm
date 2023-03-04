#include <iostream>
#include <map>
#define MAX 1048576
using namespace std;

int train[100001];
bool record[MAX];
int N, M;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    while(M--){
        int c, i, x;
        cin >> c >> i;
        switch (c)
        {
        case 1:
            cin >> x;
            if(!(train[i] & 1 << --x))
                train[i] += 1 << x;
            break;
        case 2:
            cin >> x;
            if(train[i] & 1 << --x)
                train[i] -= 1 << x;
            break;
        case 3:
            train[i] <<= 1;
            train[i] %= MAX;
            break;
        case 4:
            train[i] >>= 1;
        default:
            break;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        // cout << train[i] << '\n';
        if(!record[train[i]]){
            ans++;
            record[train[i]] = true;
        }
    }
    cout << ans;
    return 0;
}