#include <iostream>
#define MOD 998244353

void problem()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    a = a & 1 ? a * ((a + 1) >> 1) : (a >> 1) * (a + 1);
    a %= MOD;
    b = b & 1 ? b * ((b + 1) >> 1) : (b >> 1) * (b + 1);
    b %= MOD;
    c = c & 1 ? c * ((c + 1) >> 1) : (c >> 1) * (c + 1);
    c %= MOD;

    printf("%d\n", a * b % MOD * c % MOD);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
        problem();
}