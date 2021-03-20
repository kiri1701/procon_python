#include <iostream>
#include <fstream>
#include <string>

#define MAX_N 20
using namespace std;

//通常の入力
int n, k;
int a[MAX_N];

bool dfs(int i, int sum)
{
    if (i == n)
        return sum == k;

    if (dfs(i + 1, sum))
        return true;

    if (dfs(i + 1, sum + a[i]))
        return true;

    return false;
}

int main()
{
    //cinでファイルから読込
    std::ifstream in("partial_sum.txt");
    std::cin.rdbuf(in.rdbuf());

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> k;

    if (dfs(0, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
