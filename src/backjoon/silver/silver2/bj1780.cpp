#include <iostream>
using namespace std;
int ans[2];
int paper[2200][2200];

bool check(int y, int x, int size){
    int val = paper[y][x];
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(val != paper[i][j]){
                return false;
            }
        }
    }
    ans[val + 1]++;
    return true;
}

void cut(int y, int x, int size){
    if(check(y, x, size)){
        return;
    }
    
    int s = size / 3;
    for(int i = y; i < y + size; i += s){
        for(int j = x; j < x + size; j += s){
            cut(i, j, s);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    }

    cut(0, 0, N);

    printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);
}