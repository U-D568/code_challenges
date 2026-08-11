#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int problem()
{
    int N;
    scanf("%d", &N);
    const int FULL = 1 << N;
    vector<int> data(N, -1);
    vector<vector<int>> dp(FULL, vector<int>(64, -1));

    int val;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &val);
        data[i] = val;
    }

    dp[0][0] = 0;
    for (int mask = 0; mask < FULL; mask++)
    {
        for (int r = 0; r < 64; r++)
        {
            int q = dp[mask][r];
            if (q == -1)
                continue;

            for (int i = 0; i < N; i++)
            {
                if (mask & (1 << i))
                    continue;

                int a = data[i];
                int v = r + (r ^ a);
                int nr = v % 64;
                int carry = v / 64;
                int nq = 2 * q + carry;

                int next_mask = mask | (1 << i);
                dp[next_mask][nr] = max(dp[next_mask][nr], nq);
            }
        }
    }

    int max_val = 0;
    for (int r = 0; r < 64; r++)
    {
        int q = dp[FULL - 1][r];
        if (q == -1)
            continue;
        int val = 64 * q + r;
        max_val = max(max_val, val);
    }

    return max_val;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
        printf("%d\n", problem());

    return 0;
}