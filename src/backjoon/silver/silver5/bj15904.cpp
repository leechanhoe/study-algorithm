#include <iostream>
using namespace std;

string str;
int cnt;

int main(){
    getline(cin, str);

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'U' && cnt == 0){
            cnt = 1;
        }
        else if(str[i] == 'C'){
            if(cnt == 3){
                cnt = 4;
                break;
            }
            else if(cnt == 1)
                cnt = 2;
        }
        else if(str[i] == 'P' && cnt == 2){
            cnt = 3;
        }
    }
    if (cnt == 4)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
    return 0;
}