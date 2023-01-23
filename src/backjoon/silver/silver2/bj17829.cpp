#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mat[1025][1025];
int N;

int merge(int r, int c){
    vector<int> v;
    for(int i = r; i < r + 2; i++){
        for(int j = c; j < c + 2; j++)
            v.push_back(mat[i][j]);
    }
    sort(v.begin(), v.end());
    return v[2];
}

void div(int n){
    if(n == 1)
        return;
    
    for(int i = 0; i < n; i += 2){
        for(int j = 0; j < n; j += 2)
            mat[i/2][j/2] = merge(i, j);
    }
    div(n / 2);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
    }

    div(N);
    cout << mat[0][0];
}