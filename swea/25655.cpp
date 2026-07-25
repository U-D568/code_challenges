#include <iostream>

using namespace std;

// 0, 4, 8
int main()
{
    freopen("input.txt", "r", stdin);
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        if (N < 2)
        {
            cout << 0 << endl;
        }
        else
        {
            if (N % 2 == 0)
            {
                while (N > 1)
                {
                    cout << 8;
                    N -= 2;
                }
                cout << endl;
            }
            else
            {
                N--;
                cout << 4;
                while (N > 0)
                {
                    cout << 8;
                    N -= 2;
                }
                cout << endl;
            }
        }
    }

    return 0;
}