#include <iostream>
using namespace std;

int N, x, y, nx, ny, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> x >> y;

    for(int i = 1; i < N; i++){
        cin >> nx >> ny;
        if(nx <= y && y < ny)
            y = ny;
        else if(y < nx){
            ans += y-x;
            x = nx;
            y = ny;
        }
    }
    cout << ans + (y - x);
    return 0;
}