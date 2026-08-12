#include <iostream>
#include <vector>

using namespace std;

int problem()
{
    int K, N, M;
    scanf("%d %d %d", &K, &N, &M);
    vector<int> water(N, 0);

    for (int i = 0; i < M; i++)
    {
        int pos;
        scanf("%d", &pos);
        water[i] = pos;
    }

    int pos = 0, local_max = 0;
    int count = 0;

    for (int i = 0; i < M; i++)
    {
        if (pos + K >= water[i])
        {
            local_max = water[i];
            continue;
        }
        
        if (local_max == pos)
            return 0;
        
        pos = local_max;
        count++;
        if (pos + K >= water[i])
            local_max = water[i];
        else
            return 0;
    }

    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
        printf("#%d %d\n", t + 1, problem());

    return 0;
}