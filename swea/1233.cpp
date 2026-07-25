#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;


bool problem()
{
	int N;
	int index, left_child, right_child;
	char symbol;
	bool is_valid = true;
	
	scanf("%d", &N);
	vector<char> tree(N + 1);
	stack<char> stack_;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %c", &index, &symbol);
		if (index * 2 <= N)
			scanf("%d", &left_child);
		if (index * 2 + 1 <= N)
			scanf("%d", &right_child);

		if (!is_valid)
			continue;

		if (isdigit(symbol))
		{
			while (!stack_.empty() && isdigit(stack_.top()))
			{
				char left_operand = stack_.top();
				stack_.pop();

				if (stack_.empty() || isdigit(stack_.top()))
				{
					is_valid = false;
					break;
				}
				char op = stack_.top();
				stack_.pop();
			}
		}
		stack_.push(symbol);
	}

	if (!(stack_.size() == 1 && isdigit(stack_.top())))
		is_valid = false;

	return is_valid;
}

int main()
{
	freopen("input.txt", "r", stdin);

	for (int t = 0; t < 10; t++)
		printf("#%d %d\n", t + 1, problem() ? 1 : 0);

	return 0;
}