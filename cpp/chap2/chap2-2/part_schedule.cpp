#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#define MAX_N 100000
using namespace std;

int N, S[MAX_N], T[MAX_N];

pair<int, int> itv[MAX_N];

int solve()
{
    for (int i = 0; i < N; i++)
    {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv, itv + N);

    int ans = 0, t = 0;
    for (int i = 0; i < N; i++)
    {
        if (t < itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    }
    return ans;
}

int main()
{
    //cinでファイルから読込
    ifstream in("part_schedule.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N;
    for (int x = 0; x < N; ++x)
    {
        cin >> S[x];
    }
    for (int y = 0; y < N; ++y)
    {
        cin >> T[y];
    }

    cout << solve() << endl;
}
