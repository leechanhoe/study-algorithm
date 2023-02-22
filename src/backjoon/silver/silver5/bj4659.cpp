#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(1){
        string pwd;
        cin >> pwd;
        if(pwd == "end"){
            return 0;
        }

        int aei = 0;
        bool accept = false;
        int bc = 0;
        char prev = ' ';
        for(int i = 0; i < pwd.length(); i++){
            if(pwd[i] == 'a' || pwd[i] =='e' || pwd[i] == 'i' || pwd[i] == 'o' || pwd[i] == 'u'){
                aei++;
                accept = true;
                bc = 0;
            }
            else{
                bc++;
                aei = 0;
            }

            if((prev == pwd[i] && prev != 'e' && prev != 'o') || bc == 3 || aei == 3){
                accept = false;
                break;
            }
            prev = pwd[i];
        }

        if(!accept)
            cout << "<" << pwd << ">" << " is not acceptable.\n";
        else
            cout << "<" << pwd << ">" << " is acceptable.\n";
    }
    return 0;
}