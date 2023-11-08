#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int arr[300001];

int main(){
    cin >> N;
    if(N == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int ans = 0;
    int cut = round(N * 0.15);
    for(int i = cut; i < N - cut; i++){
        ans += arr[i];
    }
    ans = round(ans / (float)(N - cut * 2));
    cout << ans;
    return 0;
}