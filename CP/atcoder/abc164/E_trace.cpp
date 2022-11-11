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

struct te {
    int v;
    int s;
};
te trace[MAXN][3000];
void print_trace(int i, int j) {
    /*
    if(i == 0) return;
    print_trace(trace[i][j].v, trace[i][j].s);
    printf("%d %d\n", trace[i][j].v, trace[i][j].s);
    */
    while(i>1) {
        printf("%d %d\n", trace[i][j].v, trace[i][j].s);
       i = trace[i][j].v;
       j = trace[i][j].s; 
    }
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
    for (int t = 0; t < N; t++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int k = 0; k < G[i].size(); k++)
            {
                for (int j = 0; j <= 2500; j++)
                {
                    if (j + G[i][k].a <= 2500) {
                        dp[i][j] = min(dp[i][j], dp[G[i][k].v][j + G[i][k].a] + G[i][k].b);
                        trace[i][j].v = G[i][k].v;
                        trace[i][j].s = j+G[i][k].a;
                    }
                }
            }

            for (int j = 0; j <= 2500; j++)
            {
                if (j >= C[i]) {
                    dp[i][j] = min(dp[i][j], dp[i][j - C[i]] + D[i]);
                    trace[i][j].v = i;
                    trace[i][j].s = j-C[i];
                }
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        // 0x3f3f3f3f太小不行
        ans = 1e18;
        int ai, aj;
        for(int j=0; j<=2500; j++) {
            if(ans>dp[i][j]) {
                ans = dp[i][j];
                ai = i;
                aj = j;
            }
        }
        if(i==6) {
            print_trace(ai, aj);
        }
        cout << ans << endl;
    }

    return 0;
}