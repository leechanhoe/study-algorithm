#include <iostream>
using namespace std;

int N, M;
int arr[100001];

bool solve(int k){
    int now = k;
    int cnt = 1;
    for(int i = 0; i < N; i++){
        if(now < arr[i]){
            cnt++;
            now = k;
        }
        now -= arr[i];

        if(cnt > M)
            return false;
    }
    return true;
}

int main(){
    cin >> N >> M;

    int s = 0;
    int e = 1000000000;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        s = max(s, arr[i]);
    }

    int mid, ans;
    while(s <= e){
        
        mid = (s + e) / 2;
        if(solve(mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    cout << ans;
    return 0;
}