#include <iostream>
#include <vector>
using namespace std;

int N;
pair<int, int> ingr[11];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ingr[i].first >> ingr[i].second;
    }

    int ans = 1987654321;
    for(int i = 1; i < (1 << N); i++){
        int a = 1;
        int b = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                a *= ingr[j].first;
                b += ingr[j].second;
            }
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans;
    return 0;
}