#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	double ans;
	cout << fixed;
	cout.precision(1);

	switch (str[0])
	{
        case 'A' :
            ans = 4;
            break;
        case 'B':
            ans = 3;
            break;
        case 'C':
            ans = 2;
            break;
        case 'D':
            ans = 1;
            break;
	}	
	switch (str[1])
	{
        case '+':
            ans += 0.3;
            break;
        case '-':
            ans -= 0.3;
            break;
	}
	cout << ans;
}