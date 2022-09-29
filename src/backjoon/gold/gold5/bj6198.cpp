#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long ans;
pair<int, int> building[80001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    stack<pair<int, int>> stk;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> building[i].first;
        building[i].second = i;
    }

    for (int i = 0; i < N; i++)
    {
        while (!stk.empty() && stk.top().first <= building[i].first)
        {
            ans += i - stk.top().second - 1;
            stk.pop();
        }
        stk.push(building[i]);
    }

    while (!stk.empty())
    {
        ans += N - stk.top().second - 1;
        stk.pop();
    }
    cout << ans;
}