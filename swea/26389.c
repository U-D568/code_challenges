#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define BUFF_SIZE 1 << 10

char in_buffer[BUFF_SIZE];
int in_idx = 0; in_size = 0;
char out_buffer[BUFF_SIZE];
int out_idx = 0;

char read_char()
{
	if (in_idx >= in_size)
	{
		in_size = (int)fread(in_buffer, 1, BUFF_SIZE, stdin);
		in_idx = 0;
		if (in_size == 0)
			return EOF;
	}
	return in_buffer[in_idx++];
}

bool read_int(int* num)
{
	char ch;
	bool is_neg = false;

	while ((ch = read_char()) == ' ' || ch == '\n' || ch == '\r');
	if (ch == EOF)
		return false;
	if (ch == '-')
	{
		is_neg = true;
		ch = read_char();
	}

	*num = 0;
	while (ch != ' ' && ch != '\n' && ch != '\r' && ch != EOF)
	{
		*num *= 10;
		*num += ch - '0';
		ch = read_char();
	}

	if (is_neg)
		*num = -*num;

	return true;
}

void flush_out()
{
	if (out_idx > 0)
	{
		fwrite(out_buffer, 1, out_idx, stdout);
		out_idx = 0;
	}
}

void write_char(char ch)
{
	if (out_idx >= BUFF_SIZE)
		flush_out();
	out_buffer[out_idx++] = ch;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	read_int(&T);

	bool north = false, south = false, west = false, east = false;
	char ch;

	for (int i = 0; i < T; i++)
	{
		north = false; south = false; west = false; east = false;

		while ((ch = read_char()) != '\n' && ch != '\r' && ch != EOF)
		{
			switch (ch)
			{
			case 'N':
				north = true;
				break;
			case 'S':
				south = true;
				break;
			case 'W':
				west = true;
				break;
			case 'E':
				east = true;
				break;
			}
		}

		if (!(north ^ south) && !(west ^ east))
		{
			write_char('Y');
			write_char('e');
			write_char('s');
			write_char('\n');
		}
		else
		{
			write_char('N');
			write_char('o');
			write_char('\n');
		}
	}

	flush_out();

	return 0;
}