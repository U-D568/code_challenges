#include <iostream>
#include <vector>

using namespace std;

int problem()
{
    int N, count = 0;
    int at_cnt, cg_cnt;
    string S;
    scanf("%d", &N);
    S.resize(N);
    scanf("%s", &S[0]);

    for (int r = 0; r < N; r++)
    {
        at_cnt = 0;
        cg_cnt = 0;
        for (int c = r; c < N; c++)
        {
            switch (S[c])
            {
            case 'A':
                at_cnt--;
                break;
            case 'T':
                at_cnt++;
                break;
            case 'C':
                cg_cnt--;
                break;
            case 'G':
                cg_cnt++;
                break;
            }
            if (at_cnt == 0 && cg_cnt == 0)
                count++;
        }
    }

    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
        printf("%d\n", problem());
    return 0;
}