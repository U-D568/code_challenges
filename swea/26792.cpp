#include <iostream>
#include <vector>

using namespace std;

pair<int, int> problem()
{
    int eq1, eq2, A, B;
    scanf("%d %d", &eq1, &eq2);
    A = (eq1 + eq2) / 2;
    B = eq1 - A;

    return make_pair(A, B);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        pair<int, int> res = problem();
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}