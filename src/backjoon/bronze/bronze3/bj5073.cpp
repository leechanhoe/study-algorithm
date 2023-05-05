#include <iostream>
#include <algorithm>
using namespace std;

int a[3];

int main(){
    while(1){
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);
        if(a[0] == a[1] && a[1] == a[2] && a[2] == a[0]){
            if(a[0] == 0)
                return 0;
            cout << "Equilateral\n";
            continue;
        }
        if(a[0] + a[1] <= a[2]){
            cout << "Invalid\n";
            continue;
        }
        if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0]){
            cout << "Isosceles\n";
        }
        else
            cout << "Scalene\n";
    }
    return 0;
}