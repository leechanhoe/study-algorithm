#include <iostream>
using namespace std;

bool star[500][500];

void draw(int r, int c, int n){
    if(n == 1){
        star[r][c] = '*';
        return;
    }

    int size = (n - 1) * 4 + 1;
    for(int i = c; i < c + size; i++){
        star[r][i] = true;
        star[r+size-1][i] = true;
        star[i][c] = true;
        star[i][c+size-1] = true;
    }

    draw(r+2, c+2, n-1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    draw(0, 0, N);

    int size = (N - 1) * 4 + 1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            cout << (star[i][j] ? '*' : ' ');
        cout << '\n';
    }
    return 0;
}