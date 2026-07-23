#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long problem()
{
    int N, M;
    int max_val = -1;
    scanf("%d %d", &N, &M);
    vector<int> officers(N);

    for (int n = 0; n < N; n++)
    {
        int val;
        scanf("%d", &val);
        officers[n] = val;
        max_val = max(max_val, val);
    }

    long long left, right, mid, ans;
    left = 1;
    right = (long long)max_val * M;
    ans = right;

    while (left <= right)
    {
        long long processed = 0;
        mid = left + (right - left) / 2; // => (left + right) / 2

        for (int officer : officers)
            processed += mid / officer;
        
        if (processed < M)
            left = mid + 1;
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
    {
        long long result = problem();
        printf("#%d %lld\n", t + 1, result);
    }

    return 0;
}