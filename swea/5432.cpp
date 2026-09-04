#include <iostream>
#include <string>

using namespace std;

int solution()
{
    string line;
    cin >> line;

    int result = 0;
    int stacked = 0;
    char prev = -1;
    for (int i = 0; i < line.size(); i++)
    {
        char ch = line[i];
        if (prev == '(' && ch == ')')
        {
            stacked--;
            result += stacked;
        }
        else if (ch == ')')
        {
            stacked--;
            result++;
        }
        else if (ch == '(')
            stacked++;
        prev = ch;
    }

    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        int res = solution();
        printf("#%d %d\n", t, res);
    }

    return 0;
}