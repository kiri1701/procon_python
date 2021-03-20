#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#define MAX_N 100
#define MAX_M 100
using namespace std;

const int INF = 1000000000;

// 状態を表すクラスpairをtypedefしておくと便利
typedef pair<int, int> P;

//入力
char maze[MAX_N][MAX_M + 1]; // +1 は改行コード分?
int N, M;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// (sx, xy)から(gx, gy)までの最短距離を求める
int bfs()
{
    queue<P> que;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            d[i][j] = INF;

    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size())
    {
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 移動が可能かの判定とすでに訪れたことがあるかの判定
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main()
{
    //cinでファイルから読込
    ifstream in("Maze.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N >> M;
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < M; ++y)
        {
            cin >> maze[x][y];
            if (maze[x][y] == 'S')
            {
                sx = x;
                sy = y;
            }
            if (maze[x][y] == 'G')
            {
                gx = x;
                gy = y;
            }
        }
    }

    int res = bfs();
    cout << res << endl;
}
