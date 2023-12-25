#include <iostream>
using namespace std;

int r, c, max_;

int main(){
    r = 1;
    c = 1;
    for(int i = 1; i < 10; i++){
        for(int j = 1, n; j < 10; j++){
            cin >> n;
            if(max_ < n){
                max_ = n;
                r = i;
                c = j;
            }
        }
    }

    cout << max_ << '\n' << r << ' ' << c;
    return 0;
}