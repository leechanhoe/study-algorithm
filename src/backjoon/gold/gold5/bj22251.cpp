#include <iostream>
using namespace std;

int N, K, P, X;
int origin[6];
int dif[10][10] = {{0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
                    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
                    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
                    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
                    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
                    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
                    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
                    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
                    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
                    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}};

int convert(int a){
    int ret = 0;
    for(int i = 0; i < K; i++){
        ret += dif[origin[i]][a%10];
        a /= 10;
    }
    return ret;
}

int main(){
    cin >> N >> K >> P >> X;

    for(int i = 0; i < K; i++){
        origin[i] = X%10;
        X /= 10;
    }

    int ans = -1;
    for(int i = 1; i <= N; i++){
        if(convert(i) <= P){
            ans++;
        }
    }
    cout << ans;
}