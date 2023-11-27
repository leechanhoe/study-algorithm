#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int rank1[6] = {5000000, 3000000, 2000000, 500000, 300000, 100000};
int rank2[5] = {5120000, 2560000, 1280000, 640000, 320000};
vector<int> money1;
vector<int> money2;
int T, a, b;

int main(){
    money1.push_back(0);
    money2.push_back(0);
    for(int i = 1; i <= 6; i++){
        for(int j = 0; j < i; j++){
            money1.push_back(rank1[i-1]);
        }
    }
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j < pow(2, i); j++){
            money2.push_back(rank2[i]);
        }
    }

    cin >> T;
    while(T--){
        cin >> a >> b;
        int m1 = 0;
        int m2 = 0;
        if(a <= 21)
            m1 = money1[a];
        if(b <= 31)
            m2 = money2[b];
        cout << m1 + m2 << '\n';
    }
    return 0;
}