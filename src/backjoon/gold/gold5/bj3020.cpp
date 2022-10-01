#include <iostream>
#include <algorithm>
using namespace std;

int N, H;
int top[500002], bottom[500002], broke[500002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> H;

    int h;
    for(int i = 0; i < N; i++){
        cin >> h;
        if(i % 2 == 0)
            bottom[h]++;
        else
            top[H-h+1]++;
    }

    for(int i = 1; i <= H; i++){
        bottom[H-i+1] += bottom[H-i+2];
        top[i] += top[i-1];
    }

    for(int i = 1; i <= H; i++){
        broke[i] = top[i] + bottom[i];
    }

    int min_ = *min_element(broke + 1, broke + H + 1);
    int ans = count(broke + 1, broke + H + 1, min_);
    
    cout << min_ << ' ' << ans;
}