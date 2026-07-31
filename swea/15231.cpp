#include <iostream>

using namespace std;

int problem()
{
    int N, V;
    int cnt = 0;
    int dir = 1; // 0: left, 1: right
    scanf("%d %d", &N, &V);

    // bottom-up
    int cur = V;
    while (cur > 1)
    {
        dir = cur % 2;
        cur /= 2;
        cnt++;
    }

    // top-down
    int next = 1 * 2 + (dir == 0 ? 1 : 0);
    while (next <= N)
    {
        cnt++;
        next *= 2;
    }

    return cnt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}