#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> visited(1001, 0);
vector<int> dp(1001, 1);

void init()
{
    int forbidden, min_val = -1;
    for (int i = 2; i <= 1000; i++)
    {
        // calculates forbidden numbers
        for (int j = 1; j <= i / 2; j++)
        {
            forbidden = dp[i - j] * 2 - dp[i - 2 * j];
            if (forbidden < 0)
                continue;
            visited[forbidden] = i;
        }

        // find lowest positive integer
        for (int j = 1; j <= 1000; j++)
        {
            if (visited[j] != i)
            {
                min_val = j;
                break;
            }
        }

        dp[i] = min_val;
    }
}

int problem()
{
    int N;
    scanf("%d", &N);
    return dp[N];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    init();

    for (int t = 0; t < T; t++)
    {
        int res = problem();
        printf("%d\n", res);
    }

    return 0;
}