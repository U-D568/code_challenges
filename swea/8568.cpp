#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &v, int a, int b)
{
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int problem()
{
    int N, cnt;
    cnt = 0;
    scanf("%d", &N);
    vector<int> numbers(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int val;
        scanf("%d", &val);
        numbers[i] = val;
    }

    // greedy search
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == numbers[i] % 3)
            continue;

        int init_j = ((numbers[i] % 3 - i % 3) + 3) % 3;
        for (int j = init_j + i; j <= N; j += 3)
        {
            if (i % 3 == numbers[j] % 3 && j % 3 == numbers[i] % 3)
            {
                swap(numbers, i, j);
                cnt++;
                break;
            }
        }
    }

    // normal search
    int correct = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == numbers[i] % 3)
            continue;

        for (int j = i + 1; j <= N; j++)
        {
            // avoid correctly placed number
            if (j % 3 == numbers[j] % 3)
                continue;
            if (i % 3 == numbers[j] % 3)
            {
                swap(numbers, i, j);
                cnt++;
                break;
            }
        }
    }

    return cnt;
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

    return 0;
}