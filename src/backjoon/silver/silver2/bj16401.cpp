#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i = 0, a; i < N; i++){
        cin >> a;
        v.push_back(a);
    }
    
    int le = 1;
    int ri = *max_element(v.begin(), v.end());
    int ans = 0;
    while(le <= ri){
        int mid = (le + ri) / 2;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            cnt += v[i] / mid;
        }
        if(M <= cnt){
            le = mid + 1;
            ans = mid;
        }
        else{
            ri = mid - 1;
        }
    }

    cout << ans;
    return 0;
}