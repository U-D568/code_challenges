#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
int rows[50];
int cols[50];
 
int problem()
{
    int H, W;
    char ch;
    scanf("%d %d", &H, &W);
 
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(rows));
 
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
 
            ch = getchar();
            while (ch == '\n' || ch == '\r')
                ch = getchar();
            if (ch == '#')
            {
                rows[r]++;
                cols[c]++;
            }
        }
    }
 
    int row_cnt = 0, col_cnt = 0;
    for (int i = 0; i < H; i++)
    {
        if (rows[i] == W)
            row_cnt++;
    }
 
    for (int i = 0; i < W; i++)
    {
        if (cols[i] == H)
            col_cnt++;
    }
 
    if (row_cnt == H && col_cnt == W)
        return row_cnt < col_cnt ? row_cnt : col_cnt;
 
    return row_cnt + col_cnt;
}
 
int main()
{
    int T;
    scanf("%d", &T);
 
    for (int i = 0; i < T; i++)
    {
        printf("%d\n", problem());
    }
 
    return 0;
}