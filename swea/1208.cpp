#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int problem()
{
    int N;
    int sum = 0;
    scanf("%d", &N);

    vector<int> nums(100);
    for (int i = 0; i < 100; i++)
    {
        int val;
        scanf("%d", &val);
        nums[i] = val;
        sum += val;
    }

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    int average = sum / 100;
    int remains = sum % 100;

    for (int n : nums)
    {
        if (n < average)
            min_heap.push(n);
        else if (n > average)
            max_heap.push(n);
    }

    while (!min_heap.empty())
    {
        if (N == 0)
            break;
        int min_val = min_heap.top();
        min_heap.pop();
        min_val++;
        if (min_val < average)
            min_heap.push(min_val);

        int max_val = max_heap.top();
        max_heap.pop();
        max_val--;
        if (max_val > average)
            max_heap.push(max_val);

        N--;
    }

    if (min_heap.empty())
    {
        if (max_heap.empty())
            return 0;
        return 1;
    }
    else
        return max_heap.top() - min_heap.top();

    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    for (int t = 0; t < 10; t++)
    {
        int res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}