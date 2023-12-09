#include <iostream>
using namespace std;

int N;
int mart[1001];
int ans;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> mart[i];
    }

    int now = 0;
    for(int j = 0; j < N; j++){
        if(now == mart[j]){
            ans++;
            now = (now + 1) % 3;
        }
    }

    cout << ans;
    return 0;
}