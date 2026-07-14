#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int problem()
{
    int N;
    scanf("%d", &N);

    vector<int> data(N);
    for (int i = 0; i < N; i++)
    {
        int d;
        scanf("%d", &d);
        data[i] = d;
    }

    int max_val = data[0];
    int cur_val = data[0];
    for (int i = 1; i < N; i++)
    {
        cur_val = max(cur_val + data[i], data[i]);
        max_val = max(cur_val, max_val);
    }

    return max_val;
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
}