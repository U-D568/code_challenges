#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool problem()
{
	int N;
	cin >> N;
	float val = (float)N / 9;
	for (int i = 1; i < 10; i++)
	{
		if (N % i == 0 && N / i <= 9.0)
			return true;
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	string answer;
	for (int i = 0; i < T; i++)
	{
		answer = problem() ? "Yes" : "No";
		printf("#%d %s\n", i + 1, answer.c_str());
	}

	return 0;
}