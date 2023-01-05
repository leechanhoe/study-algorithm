#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[10001];

bool check(int mi){
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += min(arr[i], mi); // arr[i] <= mi ? arr[i] : mi;
    }
    return sum <= M;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> M;

    int lo = 0;
    int hi = *max_element(arr, arr + N);
    int mi, ans;
    while(lo <= hi){
        mi = (lo + hi) / 2;
        if(check(mi)){
            ans = mi;
            lo = mi + 1;
        }
        else{
            hi = mi - 1;
        }
    }
    cout << ans;
    return 0;
}