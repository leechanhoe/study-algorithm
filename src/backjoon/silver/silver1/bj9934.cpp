#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
int entry[1025];
int tree[1025];

void solve(int idx, int left, int right){
    int root = (left + right) / 2;
    tree[idx] = entry[root];
    if(left >= right)
        return;
    solve(idx * 2, left, root - 1);
    solve(idx * 2 + 1, root + 1, right);
}

int main(){
    cin >> K;

    int len = pow(2, K) - 1;
    for(int i = 0; i < len; i++){
        cin >> entry[i];
    }

    solve(1, 0, len - 1);

    int p = 0;
    int cnt = 0;
    for(int i = 1; i <= len; i++){
        cout << tree[i] << ' ';
        cnt++;
        if(cnt == pow(2, p)){
            p++;
            cnt = 0;
            cout << '\n';
        }
    }
    return 0;
}