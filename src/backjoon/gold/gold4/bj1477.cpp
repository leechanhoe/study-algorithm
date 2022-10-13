#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, L;
vector<int> rests;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> L;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        rests.push_back(input);
    }
    rests.push_back(0);
    rests.push_back(L);
    sort(rests.begin(), rests.end());

    int le = 0;
    int ri = L;
    int mid, ans = 0;

    while(le <= ri){
        mid = (le + ri) / 2;
        if (mid == 0){
            le = 1;
            continue;
        }

        int val = 0;
        int len = rests.size();
        for(int i = 1; i < len; i++){
            int dist = rests[i] - rests[i-1];
            val += (dist / mid);
            if(dist % mid == 0){
                val--;
            }
        }
        if(val > M){
            le = mid + 1;
        }
        else{
            ri = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
}