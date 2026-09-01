#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

int N, K;

int horizontal_scan(vector<vector<int>> &matrix)
{
    int cur_size = 0;
    int count = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (matrix[row][col] == 1)
                cur_size++;
            else if (matrix[row][col] == 0)
            {
                if (cur_size == K)
                    count++;
                cur_size = 0;
            }
        }
        if (cur_size == K)
            count++;
        cur_size = 0;
    }

    return count;
}

int vertical_scan(vector<vector<int>> &matrix)
{
    int cur_size = 0;
    int count = 0;
    for (int col = 0; col < N; col++)
    {
        for (int row = 0; row < N; row++)
        {
            if (matrix[row][col] == 1)
                cur_size++;
            else if (matrix[row][col] == 0)
            {
                if (cur_size == K)
                    count++;
                cur_size = 0;
            }
        }
        if (cur_size == K)
            count++;
        cur_size = 0;
    }

    return count;
}

int solution()
{
    scanf("%d %d", &N, &K);
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int row = 0; row < N; row++)
    {
        for( int col = 0; col < N; col++)
        {
            int val;
            scanf("%d", &val);
            matrix[row][col] = val;
        }
    }

    int count = horizontal_scan(matrix);
    count += vertical_scan(matrix);

    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
        printf("#%d %d\n", i, solution());

    return 0;
}