#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string str;
	string ans[1001];
    
	cin >> str;
	int len = str.length();

	for(int i = 0; i < len; i++){
		ans[i] = str.substr(i, len);
	}

	sort(ans, ans + len);

	for(int i = 0; i < len; i++){
		cout << ans[i] << '\n';
	}
}