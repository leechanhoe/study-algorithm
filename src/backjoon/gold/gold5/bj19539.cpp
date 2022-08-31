#include <bits/stdc++.h>
using namespace std;

int N, sum;
int tree[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> tree[i];
        sum += tree[i];
    }

    if(sum % 3 != 0){
        cout << "NO";
        return 0;
    }
    int div = sum / 3;
    int used = 0;
    for(int i = 0; i < N; i++){
        used += tree[i] / 2;
    }
    // cout << used;
    if (used < div)
        cout << "NO";
    else
        cout << "YES";
}