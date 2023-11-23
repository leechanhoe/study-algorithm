#include <iostream>
using namespace std;

int N, M;
string img1[11];
string img2[22];
string stretch[22];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> img1[i];
        stretch[i] = "";
        for(int j = 0; j < M; j++){
            stretch[i] += img1[i][j];
            stretch[i] += img1[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        cin >> img2[i];
        if(img2[i] != stretch[i]){
            cout << "Not Eyfa";
            return 0;
        }
    }
    cout << "Eyfa";
    return 0;
}