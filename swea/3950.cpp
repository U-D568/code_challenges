#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> logs;

struct Parenthesis
{
    int index;
    char value;
};

char flip(char parenthesis)
{
    return parenthesis == '(' ? ')' : '(';
}

int problem()
{
    int L, flip_count = 0;
    string S;
    cin >> L >> S;

    if (L % 2 != 0)
        return -1;

    vector<Parenthesis> p_stack;
    for (int i = 0; i < S.size(); i++)
    {
        Parenthesis current = Parenthesis{i, S[i]};
        if (p_stack.empty())
        {
            p_stack.push_back(current);
            continue;
        }

        Parenthesis &back = p_stack.back();
        if (current.value == ')' && back.value == '(')
            p_stack.pop_back();
        else
            p_stack.push_back(current);
    }

    if (p_stack.empty())
        return flip_count;

    int left = -1, right = -1;
    if (p_stack[0].value != p_stack.back().value)
    {
        right = 0;
        for (int i = 0; i < p_stack.size(); i++)
        {
            if (p_stack[0].value == p_stack[i].value)
                right++;
        }

        for (int i = 0; i < right; i++)
            p_stack[i].value = flip(p_stack[i].value);
        logs.push_back(make_pair(p_stack[0].index, p_stack[right - 1].index));
        flip_count++;
    }

    if (p_stack.back().value == ')')
    {
        left = 0;
        right = p_stack.size() / 2 - 1;
    }
    else
    {
        left = p_stack.size() / 2;
        right = p_stack.size() - 1;
    }

    logs.push_back(make_pair(p_stack[left].index, p_stack[right].index));
    flip_count++;

    return flip_count;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; tc++)
    {
        logs.clear();

        int cnt = problem();
        if (cnt > 10)
        {
            printf("#%d %d\n", tc + 1, -1);
            continue;
        }

        printf("#%d %d\n", tc + 1, cnt);
        for (pair<int, int> log : logs)
            printf("%d %d\n", log.first, log.second);
    }

    return 0;
}