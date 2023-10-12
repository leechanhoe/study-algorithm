#include <iostream>
using namespace std;

int N;
string color;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> color;

    int b = color[0] == 'B' ? 1 : 0;
    int r = 1 - b;
    for(int i = 1; i < N; i++){
        if(color[i] != color[i-1]){
            if(color[i] == 'B')
                b++;
            else
                r++;
        }
    }

    cout << min(b, r) + 1;
    return 0;
}