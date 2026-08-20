#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int num_counts[10] = { 0 };
int updated_at[10] = { -1 };

bool problem()
{
	int ch = getchar();
	bool result = true;
	memset(num_counts, 0, sizeof(num_counts));
	memset(updated_at, -1, sizeof(num_counts));

	int step = 1;
	int number;

	while (ch == '\r' || ch == '\n')
		ch = getchar();
	while (ch != '\r' && ch != '\n' && ch != EOF)
	{
		if (!result)
		{
			ch = getchar();
			continue;
		}

		int num = ch - '0';

		if (num_counts[num] > 1)
			result = false;
		if (num_counts[num] == 1)
		{
			if (!(step - updated_at[num] - 1 == num))
				result = false;
		}

		num_counts[num]++;
		updated_at[num] = step;
		step++;
		ch = getchar();
	}

	for (int n : num_counts)
	{
		if (n == 2 || n == 0)
			continue;
		return false;
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
		printf("%s\n", problem() ? "yes" : "no");

	return 0;
}
