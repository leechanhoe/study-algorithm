#include <iostream>
using namespace std;

int main(){
    string cam = "CAMBRIDGE";
    string word;
    cin >> word;

    for(int i = 0; i < word.size(); i++){
        bool out = true;
        for(int j = 0; j < cam.size(); j++){
            if(word[i] == cam[j]){
                out = false;
                break;
            }
        }
        if(out)
            cout << word[i];
    }
    return 0;
}