#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int problem()
{
    int score = 0;
    int N, L;
    scanf("%d %d", &N, &L);
 
    vector<vector<int>> dp(N + 1, vector<int>(L + 1, 0));
    vector<pair<int, int>> food_list(N + 1);
 
    for (int i = 1; i <= N; i++)
    {
        pair<int, int> food;
        scanf("%d %d", &food.first, &food.second);
        food_list[i] = food;
    }
 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (j  - food_list[i].second < 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
 
            dp[i][j] = max(dp[i - 1][j - food_list[i].second] + food_list[i].first, dp[i - 1][j]);
        }
    }
 
 
    return dp[N][L];
}
 
int main()
{
    int TC;
    scanf("%d", &TC);
 
    for (int t = 0; t < TC; t++)
    {
        int score = problem();
        printf("#%d %d\n", t + 1, score);
    }
 
    return 0;
}
