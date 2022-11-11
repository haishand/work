// 犯了两个错误，一个是循环用M而不是edge.size()，一个是INF设置0x3f3f3f3f太小
#include <iostream>
#include <vector>
#include <cstring>
#include<cmath>

#define LL long long
using namespace std;
#define MAXN 60
#define MAXA 60

int N, M, S;

struct e
{
    int u, v, a, b;
};
vector<e> edge;
int C[MAXN], D[MAXN];
LL dp[MAXN][MAXA * MAXN];
LL ans;

int main()
{
    scanf("%d%d%d", &N, &M, &S);
    int u, v, a, b;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d%d", &u, &v, &a, &b);
        edge.push_back({u, v, a, b});
        edge.push_back({v, u, a, b});
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", &C[i], &D[i]);
    }

    memset(dp, 0x3f, sizeof(dp));
    if (S > 2500)
        S = 2500;
    dp[1][S] = 0;
    while (true)
    {
        bool update = false;

        for (int i = 0; i < edge.size(); i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            int a = edge[i].a;
            int b = edge[i].b;
            for (int j = 0; j <= 2500; j++)
            {
                if (j >= C[v])
                {
                    if (dp[v][j] > dp[v][j - C[v]] + D[v])
                    {
                        update = true;
                        dp[v][j] = dp[v][j - C[v]] + D[v];
                    }
                }
                if (dp[v][j] > dp[u][j + a] + b)
                {
                    update = true;
                    dp[v][j] = dp[u][j + a] + b;
                }
            }
        }

        if (!update)
            break;
    }

    for (int i = 2; i <= N; i++)
        {
        LL ans = 1e18;
        for (int j = 0; j <= 2500; j++)
        {
            if (dp[i][j] < ans)
            {
                ans = dp[i][j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}