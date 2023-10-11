#include <iostream>
#include <cstring>
using namespace std;

int N;
int char_a[26];
int char_b[26];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        memset(char_a, 0, 26 * sizeof(int));
        memset(char_b, 0, 26 * sizeof(int));
        string a, b;
        cin >> a >> b;

        for(int j = 0; j < a.size(); j++){
            char_a[a[j] - 'a']++;
        }

        for(int j = 0; j < b.size(); j++){
            char_b[b[j] - 'a']++;
        }

        bool impo = false;
        for(int j = 0; j < 26; j++){
            if(char_a[j] != char_b[j]){
                impo = true;
                break;
            }
        }
        if(impo)
            cout << "Impossible\n";
        else
            cout << "Possible\n";
    }
    return 0;
}