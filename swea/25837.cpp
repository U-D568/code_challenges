#include <iostream>
#include <cmath>

bool problem()
{
    long long S, P;
    scanf("%lld %lld", &S, &P);
    long long low = 1;
    long long high = round(sqrt(P)) + 1;

    long long mid, prod;
    while (low <= high)
    {
        mid = (low + high) / 2;
        prod = mid * (S - mid);
        if (prod == P)
            return true;
        else if (prod < P)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        if (problem())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}