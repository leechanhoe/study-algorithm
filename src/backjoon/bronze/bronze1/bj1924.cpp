#include <iostream>
#include <string>
using namespace std;

int days[] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
string week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main() {
    int x, y;
    cin >> x >> y;

    for(int i = 1; i < x; i++)
        y += days[i];

    cout << week[y % 7];
    return 0;
}