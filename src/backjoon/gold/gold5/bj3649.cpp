#include <iostream>
#include <algorithm>
using namespace std;

int l[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x, n;
    while(cin >> x >> n){
        for(int i = 0; i < n; i++){
            cin >> l[i];
        }
        sort(l, l + n);
        x *= 10000000;

        int le = 0;
        int ri = n - 1;
        while(le < ri){
            int sum = l[le] + l[ri];
            if(sum == x){
                cout << "yes " << l[le] << ' ' << l[ri] << '\n';
                break;
            }
            else if(sum < x){
                le++;
            }
            else{
                ri--;
            }
        }
        if(le >= ri)
            cout << "danger\n";
    }
    return 0;
}