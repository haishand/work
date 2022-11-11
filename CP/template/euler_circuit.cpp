#include<iostream>
#include<vector>
#include<deque>

#define LL long long
#define MAXN 100
#define MAXM 100

using namespace std;

// 链式前向星
int nedge = 0;
int head[MAXN], Next[MAXN], edge[MAXM], to[MAXM];

/*
struct Edge {
    int to, cost;
};
vector<Edge> G[MAXN];
*/
int degree[MAXN];
int N, M;
deque<pair<int, int>> EC_edges;
int vis[MAXN][MAXN];

bool EC_exists()
{
    for (int i = 0; i < N; i++)
    {
        if (degree[i] % 2)
            return false;
    }
    return true;
}

//
void EC_find(int u)
{
    printf("\n%d-->", u);
   for(int i = head[u]; i; i=Next[i]) {
       int v = to[i];
       if(vis[u][v] || vis[v][u]) continue;
       vis[u][v] = 1; vis[v][u] = 1;
       EC_find(v);
       EC_edges.push_back(make_pair(u, v));
   } 
}

void init()
{
    for (int u = 1; u <= N; u++)
    {
        for (int i = head[u]; i; i = Next[i])
        {
            int v = to[i];
            ++degree[u];
            ++degree[v];
        }
    }
}
void add(int u, int v, int w)
{
    ++nedge;
    to[nedge] = v;
    edge[nedge] = w;
    Next[nedge] = head[u];
    head[u] = nedge;

    ++degree[u]; ++degree[v];
}

int main()
{
    scanf("%d%d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v, 1);
        add(v, u, 1);
    }

//    init();
    if (EC_exists())
        EC_find(1);

    // list circuit EC_edges
    for (int i = EC_edges.size()-1; i>=0; i--)
    {
        printf("(%d, %d)\n", EC_edges[i].first, EC_edges[i].second);
    }

printf("%d\n", sizeof char);
    return 0;
}