#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int field[100][100];

int horizontal_move(int st_row, int st_col, int dir) // -1: left, 1: right
{
    int row = st_row;
    int col = st_col;
    int val = field[row][col];
    while (val == 1 && col >= 0 && col <= 99)
    {
        col += dir;
        val = field[row][col];
    }
    col -= dir;

    return col;
}

int solution()
{
    int val;
    int target;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            scanf("%d", &val);
            field[i][j] = val;
            if (val == 2)
                target = j;
        }
    }

    int row = 99;
    int col = target;
    int value = field[row][col];
    while (row >= 0)
    {
        if (col - 1 >= 0 && field[row][col - 1] == 1) // left
        {
            col = horizontal_move(row, col, -1);
            row--;
            continue;
        }

        if (col + 1 < 100 && field[row][col + 1] == 1) // right
        {
            col = horizontal_move(row, col, 1);
            row--;
            continue;
        }

        row--;
        value = field[row][col];
    }

    return col;
}

int main()
{
    freopen("input.txt", "r", stdin);
    for (int t = 1; t <= 10; t++)
    {
        int T;
        scanf("%d", &T);
        int res = solution();
        printf("#%d %d\n", t, res);
    }

    return 0;
}