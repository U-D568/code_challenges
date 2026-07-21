#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

struct Bacteria {
    int row;
    int col;
    int count;
    int direction; // up: 1, down: 2, left: 3, right: 4
};

bool is_in_chemical(Bacteria& micro)
{
    return micro.col == 0 || micro.row == 0 || micro.col == N - 1 || micro.row == N - 1;
}

int flip_direction(int direction)
{
    switch (direction)
    {
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    case 4:
        return 3;
    }
}

void reset(vector<vector<int>>& vec)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vec[i][j] = -1;
        }
    }
}

void move(Bacteria& micro)
{
    switch (micro.direction)
    {
    case 1:
        micro.row--;
        break;
    case 2:
        micro.row++;
        break;
    case 3:
        micro.col--;
        break;
    case 4:
        micro.col++;
        break;
    }

    if (is_in_chemical(micro))
    {
        micro.count /= 2;
        micro.direction = flip_direction(micro.direction);
    }
}

int problem()
{
    scanf("%d %d %d", &N, &M, &K);

    vector<vector<int>> map(N, vector<int>(N, -1));
    vector<Bacteria> bacterias(K);
    for (int i = 0; i < K; i++)
    {
        int row, col, num, dir;
        scanf("%d %d %d %d", &row, &col, &num, &dir);
        Bacteria micro = { row, col, num, dir };
        bacterias[i] = micro;
    }

    vector<int> parents(K);
    for (int i = 0; i < K; i++)
    {
        parents[i] = i;
    }

    for (int t = 1; t <= M; t++)
    {
        reset(map);
        for (int i = 0; i < K; i++)
        {
            Bacteria& current = bacterias[i];
            if (current.count == 0)
                continue;

            // move bacteria
            move(current);

            // comparison
            if (map[current.row][current.col] == -1)
                map[current.row][current.col] = i;
            else
            {
                int other_index = map[current.row][current.col];
                Bacteria& cached = bacterias[other_index];

                if (cached.count < current.count)
                {
                    map[current.row][current.col] = i;
                    parents[other_index] = i;
                }
                else
                {
                    parents[i] = other_index;
                }
            }
        }

        // merge & parent compression
        for (int j = 0; j < K; j++)
        {
            if (j == parents[j] || bacterias[j].count == 0)
                continue;

            int root = j;
            while (root != parents[root])
                root = parents[root];
            bacterias[root].count += bacterias[j].count;
            bacterias[j].count = 0;
            parents[j] = root;
        }
    }

    int sum = 0;
    for (Bacteria b : bacterias)
    {
        sum += b.count;
    }

    return sum;
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