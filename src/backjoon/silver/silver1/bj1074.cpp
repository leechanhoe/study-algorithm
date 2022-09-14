#include <bits/stdc++.h>
using namespace std;

int f(int N, int r, int c)
{
    if (N == 0)
    {
        return 0;
    }
    return 2 * (r % 2) + (c % 2) + 4 * f(N - 1, r / 2, c / 2);
}

int main()
{
    int N, r, c;
    cin >> N >> r >> c;
    cout << f(N, r, c);
}