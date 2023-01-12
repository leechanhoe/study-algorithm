#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string arr[1001];

bool cmp(string a, string b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool** a = new bool*[2];
    a[0] = new bool[3]{false};
    a[1] = new bool[3]{false};

    if(!a[1][0])
        cout << a[1][0] << 'b';
    else{
        cout << 'a';
    }
    return 0;
}