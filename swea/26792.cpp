#include <iostream>
#include <vector>

using namespace std;

void problem()
{
    int eq1, eq2, A, B;
    scanf("%d %d", &eq1, &eq2);
    A = (eq1 + eq2) >> 1;
    B = (eq1 - eq2) >> 1;

    printf("%d %d\n", A, B);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
        problem();

    return 0;
}