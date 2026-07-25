#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Log
{
    int start;
    int end;
};

struct Bracket
{
    int index;
    char ch;
};

vector<Log> logs;

char flip(char ch)
{
    return ch == '(' ? ')' : '(';
}

int problem()
{
    vector<Bracket> b_stack;

    int L;
    string S;

    scanf("%d", &L);
    S.reserve(L);
    cin >> S;

    if (L % 2 != 0)
        return -1;

    for (int i = 0; i < S.size(); i++)
    {
        if (b_stack.empty())
        {
            b_stack.push_back(Bracket{i, S[i]});
            continue;
        }

        Bracket &top = b_stack.back();
        Bracket current = Bracket{i, S[i]};
        if (top.ch != current.ch)
        {
            if (top.ch == '(')
                b_stack.pop_back();
            else
            {
                for (Bracket &b : b_stack)
                    b.ch = flip(b.ch);

                // writes a flip log
                logs.push_back(Log{b_stack[0].index, b_stack.back().index});
                if (logs.size() > 10)
                    break;
                b_stack.push_back(current);
            }
        }
        else
            b_stack.push_back(current);
    }

    if (b_stack.size() > 0)
    {
        int st_i, end_i;
        if (b_stack.back().ch == '(')
        {
            st_i = b_stack.size() / 2;
            end_i = b_stack.size() - 1;
        }
        else
        {
            st_i = 0;
            end_i = b_stack.size() / 2 - 1;
        }
        logs.push_back(Log{b_stack[st_i].index, b_stack[end_i].index});
    }

    if (logs.size() > 10)
        return -1;

    return logs.size();
}

int main()
{
    freopen("input.txt", "r", stdin);

    int TC;
    scanf("%d", &TC);

    for (int tc = 0; tc < TC; tc++)
    {
        logs.clear();
        int result = problem();
        printf("#%d %d\n", tc + 1, result);
        for (Log log : logs)
            printf("%d %d\n", log.start, log.end);
    }

    return 0;
}