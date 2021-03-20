#include <iostream>
#include <fstream>
#include <string>

#define MAX_N 100
#define MAX_M 100
using namespace std;

//通常の入力
int N, M;
char field[MAX_N][MAX_M + 1];

void dfs(int x, int y)
{
    // 今いるところを.に置き換える
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int nx = x + dx, ny = y + dy;

            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')
                dfs(nx, ny);
        }
    }
    return;
}

int main()
{
    //cinでファイルから読込
    ifstream in("LakeCounting.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N >> M;
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < M; ++y)
        {
            cin >> field[x][y];
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == 'W')
            {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
}
