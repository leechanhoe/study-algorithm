#include <iostream>
using namespace std;

int N, K;
bool num[1001];

int main(){
    cin >> N >> K;

    for(int i = 2; i <= N; i++){
        for(int j = i; j <= N; j += i){
            if(!num[j]){
                K--;
                if(K == 0){
                    cout << j;
                    return 0;
                }
                num[j] = true;
            }
        }
    }
}