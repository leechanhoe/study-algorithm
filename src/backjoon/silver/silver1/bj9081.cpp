#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    cin >> T;

    while(T--){
        string word;
        cin >> word;

        if(!next_permutation(word.begin(), word.end())){
            prev_permutation(word.begin(), word.end());
        }
        cout << word << '\n';
    }
}