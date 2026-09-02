#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree // bottom-up
{
private:
    vector<int> tree; // stores maximum values
    int size;
    int st; // first index of ternimal nodes

public:
    SegmentTree(vector<int> &data)
    {
        st = 1;
        while(st < data.size())
            st *= 2;
        size = st * 2;
        tree.assign(size, 0);

        for (int i = 0; i < data.size(); i++)
            update(i, data[i]);
    }

    int top()
    {
        return tree[1];
    }

    void update(int index, int value)
    {
        tree[st + index] = value;
        int cur_index = st + index;
        while (cur_index > 1)
        {
            int parent_index = cur_index / 2;
            tree[parent_index] = max(tree[parent_index], tree[cur_index]);
            cur_index = parent_index;
        }
    }

    int query(int left, int right)
    {
        int lbound = st + left;
        int rbound = st + right;
        int value = -1;
        while (lbound < rbound)
        {
            if (lbound % 2 == 1) // lbound & 1
            {
                value = max(value, tree[lbound]);
                lbound++;
            }

            if (rbound % 2 == 1)
            {
                rbound--;
                value = max(value, tree[rbound]);
            }

            lbound /= 2;
            rbound /= 2;
        }

        return value;
    }
};

int solution()
{
    int N, W;
    scanf("%d %d",&N, &W);
    vector<int> memory(N);
    vector<int> blocks(W);

    for (int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        memory[i] = val;
    }

    for (int i = 0; i < W; i++)
    {
        int val;
        scanf("%d", &val);
        blocks[i] = val;
    }

    SegmentTree segtree = SegmentTree(memory);

    int left = 1;
    int right = segtree.top();
    int b_index = 0;    
    int success_count;
    int result = -1;
    while (left <= right)
    {
        success_count = 0;
        b_index = 0;
        int mid = left + (right - left) / 2;
        
        // sliding window
        int bsize =  blocks[b_index];
        for (int i = 0; i <= N - bsize; i++)
        {
            int res = segtree.query(i, i + bsize);
            if (res <= mid)
            {
                b_index++;
                success_count++;
                i += bsize - 1;
                if (success_count == W)
                    break;
            }
            bsize =  blocks[b_index];
        }

        if (success_count == W)
        {
            right = mid - 1;
            result = mid;
        }
        else
            left = mid + 1;
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