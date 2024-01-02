#include <iostream>
using namespace std;

int N, ans, max_, now;

int main(){
    cin >> N;
    for(int i = 0, h; i < N; i++){
        cin >> h;
        if(max_ < h){
            max_ = h;
            ans = max(ans, now);
            now = 0;
        }
        else{
            now++;
        }
    }
    cout << max(ans, now);
    return 0;
}