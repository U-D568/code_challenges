#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
 
using namespace std;

// https://wnsdlfkrhqnffjwnj.tistory.com/194

int operation_count;
vector<pair<int, int>> flip_pos;
vector<int> prefix;
int main(int argc, char** argv)
{
    freopen("input.txt", "r", stdin);
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int L;
        string S;
        cin >> L;
        cin >> S;
 
        //초기화
        operation_count = 0;
        flip_pos.clear();
        prefix.clear();
        // 길이가 짝수인 경우에만 동작 가능
        if (L % 2 != 0)
        {
            cout << "#" << test_case << " " << -1 << endl;
        }
        else
        {
            // 초기 음수 발생 조건 제거
            int minimum = 0, pos = -1, total = 0;
            for (int i = 0; i < L; i++)
            {
                if (S[i] == '(')
                {
                    total += 1;
                }
                else
                {
                    total -= 1;
                }
                if (total < minimum)
                {
                    minimum = total;
                    pos = i;
                }
            }
            if (pos != -1)
            {
                operation_count += 1;
                flip_pos.push_back(make_pair(0, pos));
                int start = 0, end = pos;
                while (start < end)
                {
                    char temp = S[start];
                    S[start] = S[end];
                    S[end] = temp;
                    start += 1;
                    end -= 1;
                }
                start = 0, end = pos;
                while (start <= end)
                {
                    if (S[start] == '(')
                    {
                        S[start] = ')';
                    }
                    else
                    {
                        S[start] = '(';
                    }
                    start += 1;
                }
            }
            // 누적합 카운트
            total = 0;
            for (int i = 0; i < L; i++)
            {
                if (S[i] == '(')
                {
                    total += 1;
                }
                else
                {
                    total -= 1;
                }
                prefix.push_back(total);
            }
            // 0을 만들기 위한 연산 과정
            if (prefix.back() != 0)
            {
                int target_value = prefix.back() / 2;
                pos = -1;
                for (int i = L - 1; i >= 0; i--)
                {
                    if (target_value == prefix.at(i))
                    {
                        pos = i + 1;
                        break;
                    }
                }
                flip_pos.push_back(make_pair(pos, L - 1));
                operation_count += 1;
            }
            // 결과 출력
            cout << "#" << test_case << " " << operation_count << endl;
            for (int i = 0; i < operation_count; i++)
            {
                cout << flip_pos[i].first << " " << flip_pos[i].second << endl;
            }
        }
         
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}