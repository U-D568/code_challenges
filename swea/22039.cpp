#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ostream>

using namespace std;

string impossible = "impossible";

string problem()
{
    string answer;
    int N;
    scanf("%d", &N);

    int remains = N % 3;
    if (remains == 1)
        return impossible;
    else
    {
        answer.reserve(N);
    }

    if (remains == 2)
        answer += "AB";
    else
        answer += "AAB";

    N -= answer.size();
    while (N > 0)
    {
        answer += "AAB";
        N -= 3;
    }

    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
        printf("%s\n", problem().c_str());

    return 0;
}