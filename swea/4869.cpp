#include <iostream>
#include <vector>

using namespace std;

int problem()
{
    int N;
    scanf("%d", &N);
    vector<int> dp(N / 10, 0);
    dp[0] = 1;
    dp[1] = 3;

    for(int i = 2; i < N; i++)
        dp[i] = dp[i - 1] + 2 * dp[i - 2];

    return dp.back();
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int result = problem();
        printf("#%d %d\n", t + 1, result);
    }

    return 0;
}