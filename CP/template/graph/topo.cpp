#include<bits/stdc++.h>
using namespace std;

const int MAXN  = 1e5+10;
using ll = long long;
struct edge {
    int to, w;
};
vector<edge> G[MAXN];
int N, M;
int vis[MAXN];
int in[MAXN];
vector<int> ans;

// dfs
void dfs(int s) {
    if(vis[s]) return;
    vis[s] = 1;
    for(auto e : G[s]) {
        dfs(e.to);
    }
    ans.push_back(s);
}
void tsort() {
    for(int v=1; v<=N; v++) {
        if(in[v]==0)
            dfs(v);
    }
}

// bfs
queue<int> que;
void bfs() {
    while(!que.empty()) {
        int v = que.front(); que.pop();
        ans.push_back(v);
        for(auto e : G[v]) {
            in[e.to]--;
            if(in[e.to] == 0) {
                que.push(e.to);
            }
        }
    }
}

void add(int u, int v, int w) {
    G[u].push_back({v, w});
}
int main() {
    cin >> N >> M;
    int a, b;
    for(int i=1; i<=M; i++) {
        cin >> a >> b;
        in[b]++;
        add(a, b, 1);
    }     
    /*
    // dfs
    tsort();
    reverse(ans.begin(), ans.end());
    */
    for(int v=1; v<=N; v++) {
        if(in[v] == 0) {
            que.push(v);
        }
    }
    bfs();
    for(auto v : ans) {
       cout << v << endl; 
    }
    return 0;
}