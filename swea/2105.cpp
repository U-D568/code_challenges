#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_depth = -1;
// direction 0: top-left 1: top-right 2: bottom-right 3: bottom-left
int d_row[] = { -1, -1, 1, 1 };
int d_col[] = { -1, 1, 1, -1 };

bool validate_pos(int row, int col, int N)
{
    if (row < 0 || row >= N || col < 0 || col >= N)
        return false;
    return true;
}

void dfs(vector<vector<int>>& map, vector<bool>& tasted, int row, int col, int prev_dir, int init_row, int init_col, int depth)
{
    if (prev_dir == 3 && row == init_row && col == init_col)
    {
        max_depth = max(max_depth, depth);
        return;
    }

    if (!validate_pos(row, col, map.size()) || tasted[map[row][col]])
        return;

    tasted[map[row][col]] = true;

    for (int cur_dir = prev_dir; cur_dir <= prev_dir + 1; cur_dir++)
    {
        if (cur_dir > 3)
            continue;
        dfs(map, tasted, row + d_row[cur_dir], col + d_col[cur_dir], cur_dir, init_row, init_col, depth + 1);
    }

    tasted[map[row][col]] = false;
}

int problem()
{
    int N;
    scanf("%d", &N);
    max_depth = -1;

    vector<vector<int>> map(N, vector<int>(N));
    vector<bool> tasted(101, false);

    // initialize map
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            scanf("%d", &val);
            map[i][j] = val;
        }
    }

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            tasted[map[r][c]] = true;
            dfs(map, tasted, r + d_row[0], c + d_col[0], 0, r, c, 1);
            tasted[map[r][c]] = false;
        }
    }

    return max_depth;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);
    for (int t = 0; t < TC; t++)
    {
        int res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}