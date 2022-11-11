#include <iostream>
#include <vector>
#include <cstring>

#define LL long long
using namespace std;
#define MAXN 60
#define MAXA 60

int N, M, S;

struct edge
{
    int v, a, b;
};
vector<edge> G[MAXN];
int C[MAXN], D[MAXN];
LL dp[MAXN][MAXA * MAXN];
LL ans;

inline void add(int u, int v, int a, int b)
{
    G[u].push_back({v, a, b});
    G[v].push_back({u, a, b});
}
int main()
{
    scanf("%d%d%d", &N, &M, &S);
    int u, v, a, b;
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d%d", &u, &v, &a, &b);
        add(u, v, a, b);
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d%d", &C[i], &D[i]);
    }

    memset(dp, 0x3f, sizeof(dp));
    if (S > 2500)
        S = 2500;
    dp[1][S] = 0;
    for (int t = 1; t <=2*M; t++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int k = 0; k < G[i].size(); k++)
            {
                for (int j = 0; j <= 2500; j++)
                {
                    if (j + G[i][k].a <= 2500)
                        dp[i][j] = min(dp[i][j], dp[G[i][k].v][j + G[i][k].a] + G[i][k].b);
                }
            }

            for (int j = 0; j <= 2500; j++)
            {
                if (j >= C[i])
                    dp[i][j] = min(dp[i][j], dp[i][j - C[i]] + D[i]);
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        // 0x3f3f3f3f is small should be 1e16
        ans = 1e18;
        for(int j=0; j<=2500; j++) {
            if(ans>dp[i][j]) {
                ans = dp[i][j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}