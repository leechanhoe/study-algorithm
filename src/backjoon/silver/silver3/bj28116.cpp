#include <iostream>

using namespace std;

int N;
int arr[500001];
int loc[500001];
int ans[500001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        loc[arr[i]] = i;
    }

    for(int i = 1; i <= N; i++){
        ans[i] += loc[i] - i;
        ans[arr[i]] += loc[i] - i;
        arr[loc[i]] = arr[i];
        loc[arr[i]] = loc[i];
    }

    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    return 0;
}