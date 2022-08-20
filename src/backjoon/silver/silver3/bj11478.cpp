#include <iostream>
#include <set>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
 
    set<string> set;
 
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
        str = "";
    }
 
    cout << set.size();
}
