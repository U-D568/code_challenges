#include <iostream>
#include <vector>

using namespace std;

int problem()
{
    int N;
    scanf("%d", &N);
    vector<int> nums(N);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        nums[i] = val;
        sum += val;
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int val : nums)
    {
        for (int i = sum; i >= val; i--)
        {
            if (dp[i - val])
                dp[i] = true;
        }
    }

    int cnt = 0;
    for (bool val : dp)
    {
        if (val)
            cnt++;
    }

    return cnt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int res = problem();
        printf("#%d %d\n", i + 1, res);
    }

    return 0;
}