#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

void problem()
{
    int XYZ[3];
    int A, B, C;
    bool found = false;

    scanf("%d %d %d", &XYZ[0], &XYZ[1], &XYZ[2]);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (XYZ[0] == max(XYZ[i], XYZ[j]) && XYZ[1] == max(XYZ[j], XYZ[k]) && XYZ[2] == max(XYZ[i], XYZ[k]))
                {
                    printf("%d %d %d\n", XYZ[i], XYZ[j], XYZ[k]);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
            break;
    }

    if (!found)
        printf("-1 -1 -1\n");
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        problem();
    }

    return 0;
}