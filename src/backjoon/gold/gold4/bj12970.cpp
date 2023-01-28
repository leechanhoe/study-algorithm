#include <iostream>
using namespace std;

char ab[50];

void printAns(){
    for(char ch : ab){
        cout << ch;
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        ab[i] = 'B';
    }

    if(K == 0){
        ab[N-1] = 'A';
        printAns();
        return 0;
    }
    
    int idx = N - 1;
    int cnt = 1;
    while(K > 0 && idx >= 0){
        if(idx == K){
            ab[N-idx-1] = 'A';
            printAns();
            return 0;
        }
        else if(idx < K){
            ab[N-idx-1] = 'A';
            K -= idx - cnt++;
        }
        idx--;
    }
    cout << -1;
    return 0;
}