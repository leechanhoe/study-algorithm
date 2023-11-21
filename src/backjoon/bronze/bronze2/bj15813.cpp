#include <iostream>
using namespace std;

int N, ans;
string name;

int main(){
    cin >> N >> name;
    for(int i = 0; i < N; i++){
        ans += name[i] - 'A' + 1;
    }
    cout << ans;
    return 0;
}