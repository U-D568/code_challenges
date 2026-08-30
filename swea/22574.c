#include <stdio.h>

int buffer[2001] = {0};

void init()
{
    buffer[1] = 0;
    for (int i = 1; i <= 2000; i++)
    {
        buffer[i] = buffer[i - 1] + i;
    }

    return;
}

int binary_search(int val)
{
    int left = 1;
    int right = 2000;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (val < buffer[mid])
            right = mid - 1;
        else if (val > buffer[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int solution()
{
    int N, P;
    scanf("%d %d", &N, &P);

    int index = binary_search(P);
    if (index == -1)
        return buffer[N];
    else if (index <= N)
        return buffer[N] - 1;
    return buffer[N];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    init();

    for (int t = 1; t <= T; t++)
    {
        int result = solution();
        printf("%d\n", result);
    }

    return 0;
}