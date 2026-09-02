#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree2D
{
private:
    int n;
    vector<vector<int>> tree;

public:
    FenwickTree2D(int n)
    {
        this->n = n;
        tree.assign(n + 1, vector<int>(n + 1, 0));
    }

    void update(int x, int y, int diff)
    {
        for (int i = x; i <= n; i += (i & -i))
        {
            for (int j = y; j <= n; j += (j & -j))
                tree[i][j] += diff;
        }
    }

    int query_prefix(int x, int y)
    {
        int result = 0;
        for (int i = x; i > 0; i -= (i & -i))
        {
            for (int j = y; j > 0; j -= (j & -j))
                result += tree[i][j];
        }

        return result;
    }

    int query_rect(int x1, int y1, int x2, int y2)
    {
        return query_prefix(x2, y2) - query_prefix(x1 - 1, y2) - query_prefix(x2, y1 - 1) + query_prefix(x1 - 1, y1 - 1);
    }
};

int solution()
{
    int N, M, val;
    scanf("%d %d", &N, &M);
    vector<vector<int>> board(N, vector<int>(N));
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            scanf("%d", &val);
            board[r][c] = val;
        }
    }

    FenwickTree2D fenwick(N);
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
            fenwick.update(r + 1, c + 1, board[r][c]);
    }

    int max_flies = 0;

    for (int y = 1; y <= N - M + 1; y++)
    {
        for (int x = 1; x <= N - M + 1; x++)
        {
            int y1 = y;
            int x1 = x;
            int y2 = y + M - 1;
            int x2 = x + M - 1;

            int current_flies = fenwick.query_rect(y1, x1, y2, x2);
            max_flies = max(max_flies, current_flies);
        }
    }

    return max_flies;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
        printf("#%d %d\n", t, solution());

    return 0;
}