#include<iostream>
using namespace std;

bool p[100][100];
int N, a, b, ans;

int main(){
    cin >> N;
    while(N--){
        cin >> a >> b;
        for(int i = b; i < b + 10; i++){
            for(int j = a; j < a + 10; j++)
                p[i][j] = true;
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(p[i][j])
                ans++;
        }
    }
    cout << ans;
}