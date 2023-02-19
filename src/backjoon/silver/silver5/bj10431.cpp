#include <iostream>
#include <vector>
using namespace std;

int P;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> P;
    while(P--){
        int T;
        cin >> T;

        vector<int> v;
        int ans = 0;
        for(int i = 0; i < 20; i++){
            int mm;
            cin >> mm;
            for(int j = 0; j < i; j++){
                if(v[j] > mm){
                    ans += i - j;
                    v.insert(v.begin() + j, mm);
                    break;
                }
            }
            if(v.size() == i)
                v.push_back(mm);
        }
        cout << T << ' ' << ans << '\n';
    }
    return 0;
}