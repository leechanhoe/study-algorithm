#include <iostream>
using namespace std;

int tc;

int main(){
    cin >> tc;

    while(tc--){
        string x, y;
        cin >> x >> y;

        cout << "Distances:";
        for(int i = 0; i < x.size(); i++){
            if(x[i] <= y[i]){
                cout << ' ' << y[i] - x[i];
            }
            else{
                cout << ' ' << (y[i] + 26 - x[i]);
            }
        }
        cout << '\n';
    }
}