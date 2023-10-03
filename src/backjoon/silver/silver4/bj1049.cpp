#include <iostream>
using namespace std;

int N, M;
int line[2];

int main(){
    cin >> N >> M;

    line[0] = 1000;
    line[1] = 1000;
    for(int i = 0; i < M; i++){
        int six, one;
        cin >> six >> one;
        line[0] = min(line[0], six);
        line[1] = min(line[1], one);
    }

    if(line[0] > line[1] * 6){
        cout << line[1] * N;
    }
    else{
        int ans = line[0] * (N / 6);
        ans += min(line[0], line[1] * (N % 6));
        cout << ans;
    }
    return 0;
}