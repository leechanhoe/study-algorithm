#include <iostream>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;

    if (N == 1)
        cout << 1;
    else if (N == 2)
        cout << min(4, (M + 1) / 2);
    else if (M < 7)
        cout << min(4, M);
    else
        cout << M - 7 + 5;

    return 0;
}