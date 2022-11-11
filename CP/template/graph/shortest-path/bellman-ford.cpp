// bellman-ford algorithm
#include<iostream>
#include<vector>
#include<cstring>

#define INF         0x3f3f3f3f
#define MAXN        100
#define MAX_EDGE    100

using namespace std;

struct e {
    int u, v, d;
};
int N;
vector<e> edge;
// dist[i]: s到i的最小距离
int dist[MAXN];
void bellman_ford(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    while(true) {
       bool update = false; 

       for(int i=0; i<edge.size(); i++) {
           int u = edge[i].u;
           int v = edge[i].v;
           int d = edge[i].d;
        
            if(dist[u]!=INF && dist[v] > dist[u]+d) {
                update = true;
                dist[v] = dist[u] +d;
            }
       }
       if(!update) break;
    }
}

bool find_negative_loop() {
    memset(dist, 0, sizeof(dist));
    for(int t=0; t<N; t++) {
        for(int i=0; i<edge.size(); i++) {
           int u = edge[i].u;
           int v = edge[i].v;
           int d = edge[i].d;
        
            if(dist[u]!=INF && dist[v] > dist[u]+d) {
                dist[v] = dist[u] +d;
                if(t==N-1) return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    int u, v, d;
    for(int i=0; i<N; i++) {
        scanf("%d%d%d", &u, &v, &d);
        edge.push_back({u, v, d});
        edge.push_back({v, u, d});
    }

    if(find_negative_loop()) {
        cout << "The graph has negative loop."<<endl;
        return 0;
    }
    
    bellman_ford(1);
    for(int i=2; i<=N; i++) {
        printf("%d\n", dist[i]);
    }
    return 0;
}