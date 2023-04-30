#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L, K, ans = 100;
pair<int, int> star[101];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> L >> K;
    for(int i = 0; i < K; i++){
        cin >> star[i].first >> star[i].second;
    }
    sort(star, star + K);

    for(int i = 0; i < K; i++){
        vector<pair<int, int>> inX;
        int limX = star[i].first + L;
        for(int j = i; j < K; j++){
            if(star[j].first > limX)
                break;
            inX.push_back(star[j]);
        }

        for(int j = 0; j < inX.size(); j++){
            int limY = inX[j].second + L;
            int out = K;
            for(int k = 0; k < inX.size(); k++){
                if(inX[j].second <= inX[k].second && inX[k].second <= limY){
                    out--;
                }
            }
            ans = min(ans, out);
        }
    }

    cout << ans;
    return 0;
}