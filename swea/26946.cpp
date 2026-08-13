#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int problem()
{
	int hands[2][10] = { 0 };

	bool is_end = false;
	int val, player;
	int winner = 0;
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &val);
		if (is_end)
			continue;
		player = i % 2;
		hands[player][val]++;

		if (hands[player][val] == 3)
		{
			winner = player + 1;
			is_end = true;
		}

		for (int j = max(0, val - 2); j <= min(7, val); j++)
		{
			if (hands[player][j] > 0 && hands[player][j + 1] > 0 && hands[player][j + 2] > 0)
			{
				winner = player + 1;
				is_end = true;
			}
		}
	}

	return winner;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int res = problem();
		printf("#%d %d\n", t + 1, res);
	}

	return 0;
}