#include <stdexcept>
#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

static int MAX_VAL = numeric_limits<int>::min();
static int MIN_VAL = numeric_limits<int>::max();

int calculate(int a, int b, int op)
{
    switch (op)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    default:
        throw invalid_argument("invalid operator value: " + to_string(op));
    }
}

void dfs(const vector<int> &numbers, vector<int> &operators, int depth, int left_operand)
{
    if (depth == numbers.size())
    {
        MAX_VAL = max(MAX_VAL, left_operand);
        MIN_VAL = min(MIN_VAL, left_operand);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] == 0)
            continue;
        operators[i]--;
        int result = calculate(left_operand, numbers[depth], i);
        dfs(numbers, operators, depth + 1, result);
        operators[i]++;
    }
}

int problem()
{
    int N;
    scanf("%d", &N);
    vector<int> operators(4);
    vector<int> numbers(N);

    // read operators counts
    for (int i = 0; i < 4; i++)
    {
        int cnt;
        scanf("%d", &cnt);
        operators[i] = cnt;
    }

    // read numbers
    for (int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        numbers[i] = n;
    }

    dfs(numbers, operators, 1, numbers[0]);

    return MAX_VAL - MIN_VAL;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int tc = 0; tc < TC; tc++)
    {
        MAX_VAL = numeric_limits<int>::min();
        MIN_VAL = numeric_limits<int>::max();
        int diff = problem();
        printf("#%d %d\n", tc + 1, diff);

    }

    return 0;
}
