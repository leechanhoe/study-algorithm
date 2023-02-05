#include <iostream>
using namespace std;

int k;
int lotto[14];
int ans[6];

void dfs(int idx, int depth){
    if(depth == 6){
        for(int i = 0; i < 6; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < depth + (k - 5); i++){
        ans[depth] = lotto[i];
        dfs(i + 1, depth + 1);
    }
}
int main(){
    while(cin >> k && k){
        for(int i = 0; i < k; i++){
            cin >> lotto[i];
        }
        dfs(0, 0);
        cout << '\n';
    }
    return 0;
}