#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct participant
{
	int id;
	int solved_cnt;
	int score;
	int rank = 1;
};

participant problem()
{
	int N, T, P;
	scanf("%d %d %d", &N, &T, &P);

	vector<participant> participants(N);
	vector<vector<int>> solved_list(N);
	vector<int> weights(T);

	for (int i = 0; i < N; i++)
	{
		participants[i].id = i + 1;
		for (int j = 0; j < T; j++)
		{
			int val;
			scanf("%d", &val);

			if (val == 0)
				weights[j] += 1;
			else
			{
				solved_list[i].push_back(j);
				participants[i].solved_cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j : solved_list[i])
			participants[i].score += weights[j];
	}

	for (int i = 0; i < N; i++)
	{
		if (i == P - 1)
			continue;

		if (participants[P - 1].score != participants[i].score)
		{
			if (participants[P - 1].score < participants[i].score)
				participants[P - 1].rank++;
			continue;
		}

		if (participants[P - 1].solved_cnt != participants[i].solved_cnt)
		{
			if (participants[P - 1].solved_cnt < participants[i].solved_cnt)
				participants[P - 1].rank++;
			continue;
		}

		if (participants[P - 1].id > participants[i].id)
			participants[P - 1].rank++;
	}

	return participants[P - 1];
}

int main()
{
	int TC, i;
	scanf("%d", &TC);

	for (i = 0; i < TC; i++)
	{
		participant res = problem();
		printf("#%d %d %d\n", i + 1, res.score, res.rank);
	}

	return 0;
}