#include <iostream>
#include <vector>

using namespace std;

int problem()
{
    int N, count = 0;
    scanf("%d", &N);
    vector<int> books(N + 1);
    vector<int> parent(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        int val;
        scanf("%d", &val);
        books[i] = val;
    }

    for (int i = 1; i <= N; i++)
    {
        int cur = books[i];
        if (parent[cur - 1] == 0)
        {
            parent[cur] = -1;
            count++;
        }
        else
            parent[cur] = books[cur - 1];
    }

    return count;
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