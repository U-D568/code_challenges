#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int problem()
{
    int N;
    vector<char> ch_stack;
    scanf("%d", &N);

    char ch;
    for (int i = 0; i < N; i++)
    {
        while ((ch = getchar()) == '\n' || ch == '\r');
        ch_stack.push_back(ch);

        while (true)
        {
            int size = ch_stack.size();
            if (size < 3)
                break;
            if (ch_stack[size - 1] == 'x' && ch_stack[size - 2] == 'o' && ch_stack[size - 3] == 'f')
            {
                ch_stack.pop_back();
                ch_stack.pop_back();
                ch_stack.pop_back();
            }
            else
                break;
        }
    }

    return ch_stack.size();
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
        printf("%d\n", problem());
}