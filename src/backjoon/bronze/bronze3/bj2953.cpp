#include <iostream>
#include <numeric>
using namespace std;

int score[6][4];

int main(){
    for(int i = 1; i <= 5; i++){
        for(int j = 0; j < 4; j++){
            cin >> score[i][j];
        }
    }

    int max_ = 0;
    int idx = 0;
    for(int i = 1; i <= 5; i++){
        int sum = accumulate(score[i], score[i] + 4, 0);
        if(max_ < sum){
            max_ = sum;
            idx = i;
        }
    }

    cout << idx << ' ' << max_;
    return 0;
}