#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool problem() {
    scanf("%d %d", &N, &M);
    
    bool possible1 = true;
    bool possible2 = true;
    
    char ch;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            do {
                ch = getchar();
            } while (ch == '\n' || ch == '\r');
            
            if (ch == '?') continue;

            char expected1 = ((r + c) % 2 == 0) ? '#' : '.';
            char expected2 = ((r + c) % 2 == 0) ? '.' : '#';
            
            if (ch != expected1) possible1 = false;
            if (ch != expected2) possible2 = false;
        }
    }
    
    return possible1 || possible2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
        printf("#%d %s\n", t, problem() ? "possible" : "impossible");

    return 0;
}