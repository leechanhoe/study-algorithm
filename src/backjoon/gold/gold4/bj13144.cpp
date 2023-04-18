#include <iostream>
using namespace std;

int arr[100001];
bool cnt[100001];
int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int le = 0;
    long long ans = N;
    for(int ri = 0; ri < N; ri++){
        if(cnt[arr[ri]]){
            while(arr[le] != arr[ri]){
                cnt[arr[le]] = false;
                le++;
            }
            le++;
        }
        // cout << "ri : " << ri << " le : " << le << '\n';
        cnt[arr[ri]] = true;
        ans += ri - le;
    }
    cout << ans;
    return 0;
}