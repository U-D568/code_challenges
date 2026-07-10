#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int problem()
{
	int A, B;
	cin >> A >> B;
	if (A > 9 || B > 9)
		return -1;
	return A * B;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	int answer;
	for (int i = 0; i < T; i++)
	{
		answer = problem();
		printf("#%d %d\n", i + 1, answer);
	}

	return 0;
}