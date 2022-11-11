#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define INF     0x3f3f3f3f
#define MAXN    30
using namespace std;
int G[MAXN][MAXN];
int degree[MAXN];
int dist[MAXN][MAXN];
int ans;

void solve() {
    int ov[2], n=0;
    for(int i=0; i<MAXN; i++) {
        if(degree[i]%2) {
            ov[n++] = i;
        }
    }
    if(n == 0){
        printf("%d\n", ans);
    }else {
        for(int k=0; k<MAXN; k++) {
            for(int i=0; i<MAXN; i++) {
                for(int j=0; j<MAXN;j++) {
                    if(dist[i][j]>dist[i][k]+dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        ans += dist[ov[0]][ov[1]];
        printf("%d\n", ans);
    }
}
int main() {
    string route;
    ans = 0;
    memset(degree, 0, sizeof(degree));
    memset(G, 0, sizeof(G));
    memset(dist, 0x3f, sizeof(dist));
    while(cin>>route) {
        /*
        cout<<route<<endl;
        int len = route.length();
        int u = route[0] - 'a';
        int v = route[len-1] - 'a';
        printf("%d,%d\n", u, v);
        */
        if(route == "deadend") {
            solve();
            ans = 0;
            memset(degree, 0, sizeof(degree));
            memset(G, 0, sizeof(G));
            memset(dist, 0x3f, sizeof(dist));
            continue;
        }
        int len = route.length();
        int u = route[0] - 'a';
        int v = route[len-1] - 'a';
        G[u][v] = len; G[v][u] = len;
        /*
        cout<<route;
        printf("(%d, %d)=%d\n", u, v, len);
        */
        dist[u][v] = len; dist[v][u] = len;
        ++degree[u]; ++degree[v];
        ans += len;
    }
    return 0;
}