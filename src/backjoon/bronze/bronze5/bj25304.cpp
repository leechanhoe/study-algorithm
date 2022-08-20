#include <iostream>
using namespace std;

int X, N, a, b, sum;

int main(){
    cin >> X >> N;
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        sum += a * b;
    }
    if(sum == X)
        cout << "Yes";
    else
        cout << "No";
}