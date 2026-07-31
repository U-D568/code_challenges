#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[10000];
int row_max[100];
int col_max[100];

bool problem()
{
    int cols, rows, val, r, c;
    cin >> rows >> cols;
    for (r = 0; r <= rows; r++)
        row_max[r] = -1;
    for (c = 0; c <= cols; c++)
        col_max[c] = -1;

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            cin >> val;
            matrix[r * cols + c] = val;
            col_max[c] = max(col_max[c], val);
            row_max[r] = max(row_max[r], val);
        }
    }

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            val = matrix[r * cols + c];
            if (row_max[r] != val && col_max[c] != val)
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
        cout << "#" << t + 1 << (problem() ? " YES" : " NO") << "\n";

    return 0;
}