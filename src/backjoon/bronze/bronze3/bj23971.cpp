#include <iostream>
using namespace std;

long long H, W, N, M;

int main(){
    cin >> H >> W >> N >> M;

    cout << (((H - 1) / (N + 1) + 1) * ((W - 1) / (M + 1) + 1));
}