#include <iostream>
using namespace std;

int N, S, ans;
int arr[21];
bool visit[21];

void dfs(int n, int sum, int idx){
    if(n > 0 && sum == S){
        ans++;
    }

    for(int i = idx; i < N; i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(n + 1, sum + arr[i], i + 1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0, 0, 0);

    cout << ans;
    return 0;
}