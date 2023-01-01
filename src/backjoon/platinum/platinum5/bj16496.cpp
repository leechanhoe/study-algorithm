#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string arr[1001];

bool cmp(string a, string b){
    if(a + b > b + a)
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    bool allZero = true;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] != "0")
            allZero = false;
    }

    if(allZero)
        cout << 0;
    else{
        sort(arr, arr + N, cmp);
        for(string s : arr)
            cout << s;
    }
    return 0;
}