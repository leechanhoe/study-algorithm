#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

bool is_ok(int mid){
    int num = 0;
    for(auto& j : v){
        num += j / mid;
        if(j % mid != 0)
            num++;
    }
    return num <= N;
}

int main(){
    cin >> N >> M;
    for(int i = 0, x; i < M; i++){
        cin >> x;
        v.push_back(x);
    }

    int mi = 1;
    int ma = 1000000000;
    int ans = mi;
    while(mi <= ma){
        int mid = (mi + ma) / 2;
        if(is_ok(mid)){
            ma = mid - 1;
            ans = mid;
        }
        else{
            mi = mid + 1;
        }
    }

    cout << ans;
}