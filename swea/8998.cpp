#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Task
{
    int d;
    int t;
    bool operator<(const Task &other) const
    {
        return this->d < other.d;
    }
};

int problem()
{
    int N;
    int d, t;
    cin >> N;

    vector<Task> tasks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> t >> d;
        tasks[i].d = d;
        tasks[i].t = t;
    }

    sort(tasks.begin(), tasks.end());

    int maxStart = numeric_limits<int>::max();
    for (int i = N - 1; i >= 0; i--)
    {
        const Task& task = tasks[i];
        if (task.d < maxStart)
            maxStart = task.d;
        maxStart -= task.t;
    }

    return maxStart;
}

int main(int argc, char **argv)
{
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    int res;
    for (int t = 0; t < T; t++)
    {
        res = problem();
        printf("#%d %d\n", t + 1, res);
    }

    return 0;
}