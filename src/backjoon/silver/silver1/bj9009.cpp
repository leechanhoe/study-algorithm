#include <iostream>
#include <vector>
using namespace std;

int fibo[50];

int main(){
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i < 46; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        vector<int> v;
        cin >> n;
        for(int i = 45; i > 0; i--){
            if(n - fibo[i] >= 0){
                v.push_back(fibo[i]);
                n -= fibo[i];
            }

        }

        for(int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}