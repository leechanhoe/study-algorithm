#include <iostream>
#include <algorithm>
using namespace std;

struct medal {
    int num;
    int gold;
    int silver;
    int bronze;
};

int N, K;
medal country[1001];

bool cmp(medal a, medal b){
    if(a.gold > b.gold)
        return true;
    if(a.gold == b.gold){
        if(a.silver > b.silver)
            return true;
        if(a.silver == b.silver){
            if(a.bronze > b.bronze)
                return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> country[i].num >> country[i].gold >> country[i].silver >> country[i].bronze;
    }
    sort(country, country + N, cmp);

    int idx = 0;
    for(int i = 0; i < N; i++){
        if(country[i].num == K){
            idx = i;
            break;
        }
    }

    int same = 0;
    for(int i = idx - 1; i >= 0; i--){
        if(country[idx].gold != country[i].gold || country[idx].silver != country[i].silver || country[idx].bronze != country[i].bronze){
            break;
        }
        same++;
    }
    cout << idx - same + 1;
}