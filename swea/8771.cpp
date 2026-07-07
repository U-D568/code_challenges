#include <iostream>
 
using namespace std;
 
long long problem()
{
    long long N, A, B;
    scanf("%lld %lld %lld", &N, &A, &B);
 
    if (A > B)
        return 0;
    if (N == 1 && A != B)
        return 0;

    return (N - 2) * (B - A) + 1;
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
 
    for (int i = 0; i < T; i++)
    {
        long long count = problem();
        printf("#%d %lld\n", i + 1, count);
    }
 
    return 0;
}