#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    cin >> input;

    sort(input.begin(), input.end(), greater<>());

    if (input[input.length()-1] != '0')
        cout << -1;
    else {
        long long sum = 0;
        for (auto ch : input) {
            sum += ch - '0';
        }
        if (sum % 3 == 0)
            cout << input;
        else
            cout << -1;
    }
}