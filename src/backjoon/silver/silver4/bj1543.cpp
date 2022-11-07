#include <iostream>
#include <string>
using namespace std;

int main(){
    string doc, word;
    int ans = 0;
    getline(cin, doc);
    getline(cin, word);

    if(doc.length() < word.length()){
        cout << 0;
        return 0;
    }

    for(int i = 0; i <= doc.length() - word.length(); i++){
        string sub = doc.substr(i, word.length());
        if(sub == word){
            ans++;
            i += (word.length() - 1);
        }
    }

    cout << ans;
    return 0;
}