#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

char str[8];

int problem()
{
    scanf("%s", str);
    int length = strlen(str);

    int left = atoi(str);
    int right = 0;
    int min_val = INT_MAX;
    int value;
    for (int i = 0; i < length - 1; i++)
    {
        int multiplier = 1;
        for (int j = 0; j < i; j++)
            multiplier *= 10;
        right += (left % 10) * multiplier;
        left /= 10;
        value = left + right;
        min_val = min_val < value ? min_val : value;
    }

    return min_val;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
        printf("#%d %d\n", i + 1, problem());

    return 0;
}