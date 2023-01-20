#include <iostream>
using namespace std;

char mo[3] = {'m', 'o', 'o'};
int N;

void moo(int k, int len, int n){
    int nlen = len*2 + k + 3;

    if(n <= 3){
        cout << mo[n-1];
        exit(0);
    }

    if(nlen < n){
        moo(k+1, nlen, n);
    }
    else{
        if(len < n && len + k + 3 >= n){
            cout << (len + 1 == n ? 'm' : 'o');
            exit(0);
        }
        moo(1, 3, n - (len + k + 3));
    }
}

int main(){
    cin >> N;

    moo(1, 3, N);
}