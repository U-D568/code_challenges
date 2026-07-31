#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos
{
    int row;
    int col;
};

int problem()
{
    int N, max_val;
    scanf("%d", &N);
    vector<vector<int>> map(N, vector<int>(N));
    vector<pos> people_list;
    vector<pos> stair_list;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            scanf("%d", &val);
            map[i][j] = val;
            if (val > 1)
            {
                pos stair = {i, j};
                stair_list.push_back(stair);
            }
            else if (val == 1)
            {
                pos person = {i, j};
                people_list.push_back(person);
            }
        }
    }

    for (pos person : people_list)
    {
        for (pos stair : stair_list)
        {
            
        }
    }

    return 0;
}

int main()
{
    int TC;
    scanf("%d", &TC);

    for (int tc = 0; tc < TC; tc++)
    {
        int val = problem();
        printf("#%d %d", tc + 1, val);
    }

    return 0;
}