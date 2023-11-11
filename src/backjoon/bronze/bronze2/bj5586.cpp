#include <iostream>
using namespace std;

string str;
int cntj, cnti;

int main(){
    cin >> str;
    for(int i = 0; i < str.size() - 2; i++){
        if(str[i] == 'J'){
            if(str[i+1] == 'O' && str[i+2] == 'I'){
                cntj++;
            }
        }
        else if(str[i] == 'I'){
            if(str[i+1] == 'O' && str[i+2] == 'I'){
                cnti++;
            }
        }
    }

    cout << cntj << '\n' << cnti;
    return 0;
}