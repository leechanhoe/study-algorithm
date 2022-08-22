#include <iostream>
#include <string>
using namespace std;

int check(string s, int start, int end, int del){
    while(start < end){
        if (s[start] != s[end]){
            if (del == 0){
                if (min(check(s, start + 1, end, 1), check(s, start, end - 1, 1)) == 0)
                    return 1;
                return 2;
            }
            else
                return 2;
        }
        start++;
        end--;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, start, end;
    string str;

    cin >> N;
    while(N--){
        cin >> str;
        cout << check(str, 0, str.size() - 1, 0) << '\n';
    }
}