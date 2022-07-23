#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
bool ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    cin >> t;

    while(1) {
        if (s.size() == t.size()) {
            if (s == t)
                ans = 1;
            break;
        }

        if(t[t.size() - 1] == 'B') {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        else
            t.pop_back();
    }
    cout << ans << endl;
}