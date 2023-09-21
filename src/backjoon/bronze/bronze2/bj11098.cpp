#include <iostream>
using namespace std;

int n, p;
pair<int, string> player[101];

int main(){
    cin >> n;

    while(n--){
        int max = 0;
        int idx;
        cin >> p;
        
        for(int i = 0; i < p; i++){
            cin >> player[i].first >> player[i].second;
            if(player[i].first > max){
                max = player[i].first;
                idx = i;
            }
        }

        cout << player[idx].second << '\n';
    }
    return 0;
}