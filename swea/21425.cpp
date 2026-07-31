#include <iostream>

using namespace std;

int problem()
{
    int A, B, N, cnt = 1;
    scanf("%d %d %d", &A, &B, &N);
    while (A + B <= N)
    {
        if (A < B)
            A += B;
        else
            B += A;
        cnt++;
    }

    return cnt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
        printf("%d\n", problem());
}