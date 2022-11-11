#include<iostream>
#include<queue>

#define MAXV    1000
#define INF     0x3f3f3f3f
using namespace std;
typedef pair<int, int> pii;

struct edge {
    int to, cost;
};
vector<edge> G[MAXV];
int d[MAXV];
int V, M;

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> que;
    fill(d+1, d+V+1, INF);
    d[s] = 0;
    que.push(pii(d[s], s));
    while(!que.empty()) {
        pii p = que.top(); que.pop();
        int u = p.second;
        if(d[u]<p.first) continue;
        for(int i=0; i<G[u].size(); i++) {
            edge e = G[u][i];
            if(d[e.to]>d[u]+e.cost) {
                d[e.to] = d[u]+e.cost;
                que.push(pii(d[e.to], e.to));
            }
        }
    }
}

void add(int a, int b, int c) {
    G[a].push_back({b, c});
    G[b].push_back({a, c});
}
int main() {
    scanf("%d%d", &V, &M);
    int a, b, c; 
    for(int i=0; i<M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    dijkstra(1);
    for(int i=1; i<=V; i++) {
        printf("%d\n", d[i]);
    }
    return 0;
}