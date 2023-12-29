#include <iostream>
using namespace std;

int n, sum, ans;
int ri = 1;
int le = 1;

int main(){
    cin >> n;
    while(le <= ri && ri <= n){
        if(sum < n){
            sum += ri++;
        }
        else{
            if(sum == n){
                ans++;
            }
            sum -= le++;
        }
    }

    cout << ans + 1;
    return 0;
}