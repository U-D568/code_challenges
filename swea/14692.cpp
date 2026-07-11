#include <iostream>

using namespace std;

string problem()
{
    int N;
    scanf("%d", &N);
    if (N % 2 == 0)
        return "Alice";
    else
        return "Bob";
}

int main()
{
    freopen("input.txt", "r", stdin);
    int TC;
    scanf("%d", &TC);

    for (int t = 0; t < TC; t++)
    {
        string winner = problem();
        printf("#%d %s\n", t + 1, winner.c_str());
    }
}