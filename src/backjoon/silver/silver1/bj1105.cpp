#include <iostream>
using namespace std;

string L, R;

int main(){
    cin >> L >> R;

    if(L.length() != R.length()){
        cout << 0;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < L.size(); i++){
        if(L[i] == R[i]){
            if(L[i] == '8')
                ans++;
        }
        else
            break;
    }

    cout << ans;
}