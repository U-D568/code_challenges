#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct Answer
{
    int room;
    int max_step;
};

bool is_valid(int a, int b)
{
    return !(a < 0 || b < 0 || a >= N || b >= N);
}

int dfs(vector<vector<int>>& map, vector <vector<int>>& memo, int row, int col)
{
    int count = 1;

    for (int i = 0; i < 4; i++)
    {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        // validation
        if (!(is_valid(new_row, new_col)))
            continue;

        // Memoization
        if (memo[new_row][new_col] > 0)
        {
            if (map[new_row][new_col] - map[row][col] == 1)
                count = max(count, memo[new_row][new_col] + 1);
            else if (map[new_row][new_col] - map[row][col] == -1)
                count = max(count, memo[new_row][new_col] - 1);
            continue;
        }

        if (map[new_row][new_col] - map[row][col] == 1)
            count = max(count, dfs(map, memo, new_row, new_col));
    }

    memo[row][col] = count;

    return count + 1;
}

Answer problem()
{
    Answer answer = { -1, -1 };
    scanf("%d", &N);

    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<int>> memo(N, vector<int>(N, 0));
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

    bool skip = false;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            // manually find the depth
            dfs(map, memo, r, c);
            if (answer.max_step < memo[r][c])
            {
                answer.max_step = memo[r][c];
                answer.room = map[r][c];
            }
            else if (answer.max_step == memo[r][c])
            {
                answer.room = min(answer.room, map[r][c]);
            }
        }
    }

    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
    {
        Answer ans = problem();
        printf("#%d %d %d\n", t + 1, ans.room, ans.max_step);
    }

    return 0;
}