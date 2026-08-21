#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MergeSortTree
{
private:
    int N, S;
    vector<vector<int>> tree;

    int count_greater(const vector<int> &v, int k)
    {
        auto it = upper_bound(v.begin(), v.end(), k);
        return v.end() - it;
    }

public:
    MergeSortTree(const vector<int> &arr)
    {
        N = (int)arr.size();
        S = 1;
        while (S < N)
            S = S << 1;
        tree.resize(2 * S);

        for (int i = 0; i < N; i++)
            tree[S + i].push_back(arr[i]);

        for (int i = S - 1; i >= 1; i--)
        {
            tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
            merge(tree[i * 2].begin(), tree[i * 2].end(),
                  tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(),
                  tree[i].begin());
        }
    }

    int query(int left, int right, int k)
    {
        left = left - 1 + S;
        right = right + S;

        int answer = 0;

        while (left < right)
        {
            if (left & 1)
            {
                answer += count_greater(tree[left], k);
                left++;
            }

            if (right & 1)
            {
                right--;
                answer += count_greater(tree[right], k);
            }

            left = left >> 1;
            right = right >> 1;
        }

        return answer;
    }
};

vector<int> problem()
{
    int N, M;
    int L, R, K;
    scanf("%d", &N);

    int bst_size = 1;
    while (bst_size < N)
        bst_size <<= 1;
    vector<int> arr(N);
    vector<int> results;

    for (int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        arr[i] = val;
    }

    MergeSortTree mst(arr);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &L, &R, &K);
        int result = mst.query(L, R, K);
        results.push_back(result);
    }

    return results;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        printf("#%d", t + 1);
        vector<int> result = problem();
        for (int num : result)
            printf(" %d", num);
        printf("\n");
    }

    return 0;
}