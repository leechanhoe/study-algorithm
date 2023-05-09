#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        v.insert(v.end() - a, i);
    }

    for(int a : v)
        cout << a << ' ';
    return 0;
}