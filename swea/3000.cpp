#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>

#define MOD 20171109

using namespace std;

void moderate(priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap)
{
    int diff = max_heap.size() - min_heap.size();
    while (abs(diff) > 1)
    {
        if (diff > 1)
        {
            int max_item = max_heap.top();
            max_heap.pop();
            min_heap.push(max_item);
        }
        else if (diff < -1)
        {
            int min_val = min_heap.top();
            min_heap.pop();
            max_heap.push(min_val);
        }
        diff = max_heap.size() - min_heap.size();
    }
}

int problem()
{
    int N, A;
    scanf("%d %d", &N, &A);
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    max_heap.push(A);

    int X, Y, sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X, &Y);
        int diff = max_heap.size() - min_heap.size();
        int mid = diff > 0 ? max_heap.top() : min_heap.top();

        if (mid < X)
            min_heap.push(X);
        else
            max_heap.push(X);

        if (mid < Y)
            min_heap.push(Y);
        else
            max_heap.push(Y);

        moderate(max_heap, min_heap);

        diff = max_heap.size() - min_heap.size();
        mid = diff > 0 ? max_heap.top() : min_heap.top();

        sum = (sum + mid % MOD) % MOD;
    }

    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}