#include <iostream>
using namespace std;

int N, M, ans;
bool diff;
string mat1[51];
string mat2[51];

void change(int r, int c){
    for(int i = r; i < r + 3; i++){
        for(int j = c; j < c + 3; j++){
            mat1[i][j] = mat1[i][j] == '0' ? '1' : '0';
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> mat1[i];
    }
    for(int i = 0; i < N; i++){
        cin >> mat2[i];
        if(mat1[i] != mat2[i])
            diff = true;
    }

    if(!diff){
        cout << 0;
        return 0;
    }
    
    if(N < 3 || M < 3){
        cout << -1;
        return 0;
    }

    for(int i = 0; i < N - 2; i++){
        for(int j = 0; j < M - 2; j++){
            if(mat1[i][j] != mat2[i][j]){
                change(i, j);
                ans++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(mat1[i] != mat2[i]){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}