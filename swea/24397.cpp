#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

void problem()
{
    long long X, Y, Z;
    long long result = 1;
    scanf("%lld %lld %lld", &X, &Y, &Z);

    bool flag = Y * log(X) >= log(1000) + log(Z); // true if the value has exceeded 1000
    long long modifier = 1000 * Z;

    while (Y > 0)
    {
        if (Y % 2 == 1)
            result = (result * (X % modifier)) % modifier;
        X = (X % modifier) * (X % modifier) % modifier;
        Y /= 2;
    }

    result = result * 1000 / Z % 1000000;

    if (flag)
        printf("%03lld.%03lld\n", result / 1000, result % 1000);
    else
        printf("%lld.%03lld\n", result / 1000, result % 1000);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
        problem();

    return 0;
}