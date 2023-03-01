#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int a[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;

    sort(a, a + n);

    int le = 0, ri = n - 1;
    int ans = 0;
    while(1){
        if(le == ri)
            break;

        int sum = a[le] + a[ri];
        if(sum == x){
            ans++;
            ri--;
        }
        else if (sum < x){
            le++;
        }
        else{
            ri--;
        }
    }
    cout << ans;
    return 0;
}