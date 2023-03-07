#include <iostream>
#include <cmath>
using namespace std;

int N;

void hanoi(int n, int start, int mid, int end){
    if(n == 1){
        cout << start << ' ' << end << '\n';
        return;
    }

    hanoi(n - 1, start, end, mid);
    cout << start << ' ' << end << '\n';
    hanoi(n - 1, mid, start, end);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    string str = to_string(pow(2, N));
    int x = str.find('.');
    str = str.substr(0, x);
    str[str.length() - 1] -= 1;
    cout << str << '\n';

    if(N <= 20)
    hanoi(N, 1, 2, 3);
    
    return 0;
}