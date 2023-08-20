#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int house[200001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> house[i];

    sort(house, house + N);
    cout << house[(N - 1) / 2];
    return 0;
}