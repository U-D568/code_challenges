#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

struct Brick {
    int row;
    int col;
    int value;
};

int N, W, H;
int global_min = numeric_limits<int>::max();
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

// utilizies
void print(vector<vector<int>>& matrix)
{
    for (vector<int> row : matrix)
    {
        for (int item : row)
        {
            printf("%d ", item);
        }
        printf("\n");
    }
}

bool is_valid(int row, int col)
{
    return !(row < 0 || col < 0 || row >= H || col >= W);
}

int opposite(int direction)
{
    switch (direction)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    }
    return -1;
}

int get_remains(vector<vector<int>>& matrix)
{
    int cnt = 0;
    for (vector<int> row : matrix)
    {
        for (int item : row)
        {
            if (item > 0)
                cnt++;
        }
    }

    return cnt;
}

void adjust(vector<vector<int>>& matrix)
{
    for (int c = 0; c < W; c++)
    {
        int gap = 0;
        for (int r = H - 1; r >= 0; r--)
        {
            if (matrix[r][c] == 0)
                gap++;
            else if (gap > 0)
            {
                matrix[r + gap][c] = matrix[r][c];
                matrix[r][c] = 0;
            }
        }
    }
}

int exposion(vector<vector<int>>& matrix, int row, int col)
{
    int break_count = 0;
    queue<Brick> explosion_queue;
    explosion_queue.push(Brick{ row, col, matrix[row][col] });
    matrix[row][col] = 0;
    break_count++;

    while (!explosion_queue.empty())
    {
        Brick brick = explosion_queue.front();
        explosion_queue.pop();

        for (int dir = 0; dir < 4; dir++) // direction: down, up, left, right
        {
            for (int j = 1; j <= brick.value - 1; j++)
            {
                int new_row = brick.row + dr[dir] * j;
                int new_col = brick.col + dc[dir] * j;

                if (!is_valid(new_row, new_col))
                    break;

                if (matrix[new_row][new_col] > 0)
                {
                    explosion_queue.push(Brick{ new_row, new_col, matrix[new_row][new_col] });
                    matrix[new_row][new_col] = 0;
                    break_count++;
                }
            }
        }
    }

    return break_count;
}

int get_top_index(vector<vector<int>>& matrix, int col) // optimize
{
    int row;
    for (row = 0; row < H; row++)
    {
        if (matrix[row][col] == 0)
            continue;
        return row;
    }

    return -1;
}

void dfs(vector<vector<int>> matrix, int depth, int max_depth, int remains)
{
    int cur_remains = remains;
    vector<vector<int>> temp_matrix = matrix;
    if (depth > max_depth)
    {
        global_min = min(global_min, cur_remains);
        return;
    }

    int empty_columns = 0;
    for (int w = 0; w < W; w++)
    {
        cur_remains = remains;
        temp_matrix = matrix;
        int h = get_top_index(temp_matrix, w);
        if (h < 0)
        {
            empty_columns++;
            continue;
        }

        cur_remains -= exposion(temp_matrix, h, w);
        adjust(temp_matrix);
        dfs(temp_matrix, depth + 1, max_depth, cur_remains);
    }

    if (empty_columns == W)
        global_min = 0;
}

int problem()
{
    scanf("%d %d %d", &N, &W, &H);

    int remains = 0;
    vector<vector<int>> matrix(H, vector<int>(W));

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            int val;
            scanf("%d", &val);
            matrix[h][w] = val;

            if (val > 0)
                remains++;
        }
    }

    dfs(matrix, 1, N, remains);

    return global_min;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
    {
        // reset
        global_min = numeric_limits<int>::max();

        int result = problem();
        printf("#%d %d\n", t + 1, result);
    }

    return 0;
}