#include <iostream>
#include <map>
using namespace std;

int T;

int main(){
    cin >> T;
    
    while(T--){
        string buf;
        getline(cin, buf);
        string sound;
        getline(cin, sound);
        map<string, bool> m;
        while(1){
            string a, b, c;
            cin >> a >> b >> c;
            if(a == "what"){
                cin >> b >> c;
                break;
            }
            m[c] = true;
        }
        string ans = "";
        for(int i = 0; i < sound.size(); i++){
            if (sound[i] == ' '){
                if(!m[ans]){
                    cout << ans << ' ';
                }
                ans = "";
            }
            else{
                ans += sound[i];
            }
        }
        if(!m[ans])
            cout << ans;
        cout << '\n';
    }
    return 0;
}