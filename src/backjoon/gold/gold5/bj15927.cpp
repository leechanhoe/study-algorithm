#include <iostream>
#include <string>
using namespace std;

string str;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> str;
    
	bool flag = false;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size()-i-1]) {
			cout << str.size();
			return 0;
		}
		else if (str[i] != str[i + 1]){
			flag = true;
        }
	}

	if (flag) 
        cout << str.size() - 1;
	else 
        cout << -1;
}