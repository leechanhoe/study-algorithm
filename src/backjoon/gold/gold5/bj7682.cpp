#include <string>
#include <iostream>
using namespace std;

char map[3][3];
string board;

bool win(char ox)
{
    for (int i = 0; i < 3; i++)
    {
        if ((map[i][0] == ox && map[i][0] == map[i][1] && map[i][1] == map[i][2]) || (map[0][i] == ox && map[0][i] == map[1][i] && map[1][i] == map[2][i]))
            return true;
    }

    if ((map[0][0] == ox && map[0][0] == map[1][1] && map[1][1] == map[2][2]) || (map[0][2] == ox && map[0][2] == map[1][1] && map[1][1] == map[2][0]))
        return true;

    return false;
}

int main()
{
    cin >> board;

    while (board != "end")
    {
        int o = 0;
        int x = 0;
        for (int i = 0; i < 9; i++)
        {
            map[i / 3][i % 3] = board[i];
            if (board[i] == 'O')
                o++;
            else if (board[i] == 'X')
                x++;
        }

        bool oWin = win('O');
        bool xWin = win('X');

        if ((xWin && !oWin && x - o == 1) || (!xWin && oWin && x == o) || (!xWin && !oWin && x == 5 && o == 4))
        {
            // cout << xWin << ' ' << oWin << ' ' << o << ' ' << x << " \n";
            cout << "valid\n";
        }
        else
        {
            // cout << xWin << ' ' << oWin << ' ' << o << ' ' << x << " \n";
            cout << "invalid\n";
        }
        cin >> board;
    }
}