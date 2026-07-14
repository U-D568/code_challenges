#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
 
using namespace std;
 
int main()
{
    int N;
    scanf("%d", &N);
 
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
 
    int val, mid;
    scanf("%d", &val);
    mid = val;
    max_heap.push(val);
 
    for (int i = 1; i < N; i++)
    {
        scanf("%d", &val);
 
        if (val <= mid)
            max_heap.push(val);
        else
            min_heap.push(val);
 
        int diff = min_heap.size() - max_heap.size();
        if (abs(diff) >= 2)
        {
            if (diff < 0)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
 
        diff = min_heap.size() - max_heap.size();
        if (diff < 0)
            mid = max_heap.top();
        else if (diff > 0)
            mid = min_heap.top();
        else
            mid = max_heap.top();
    }
 
    printf("%d\n", mid);
 
    return 0;
}