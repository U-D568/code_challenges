#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int volume;
    int value;
};

int problem()
{
    int N, K;
    scanf("%d %d", &N, &K);
    vector<Item> items(N + 1, Item{-1, -1});
    vector<int> dp(K + 1, 0);

    int v, c;
    for (int n = 1; n <= N; n++)
    {
        scanf("%d %d", &v, &c);
        items[n] = Item{v, c};
    }

    for (int i = 1; i <= N; i++)
    {
        for (int k = K; k >= items[i].volume; k--)
        {
            dp[k] = max(dp[k], dp[k - items[i].volume] + items[i].value);
        }
    }

    return dp.back();
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int result = problem();
        printf("#%d %d\n", i + 1, result);
    }

    return 0;
}