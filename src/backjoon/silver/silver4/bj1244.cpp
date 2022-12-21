#include <iostream>
using namespace std;

int sw[101];
int N, st, g, num;

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> sw[i];
    }

    cin >> st;
    for(int i = 0; i < st; i++){
        cin >> g >> num;

        if(g == 1){
            for(int j = num; j <= N; j += num){
                sw[j] =! sw[j];
            }
        }
        else{
            sw[num] =! sw[num];
            for(int j = 1; sw[num+j] == sw[num-j] && num+j <= N && num-j > 0; j++){
                sw[num+j] =! sw[num+j];
                sw[num-j] =! sw[num-j];
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << sw[i] << ' ';
        if(i % 20 == 0)
            cout << '\n';
    }
}