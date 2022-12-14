#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2005;

//int g[maxn][maxn];
vector<vector<int>> g;
bool vis[maxn];
int n, m;

void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	/*
	for(int v=1; v<=n; v++) {
		if(g[u][v]) {
			dfs(v);
		}
	}
	*/
	for(auto v : g[u]) {
		dfs(v);	
	}
}
int main() {
	cin >> n >> m;
	g.resize(n+1);
//	memset(g, 0, sizeof(g));
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
//		g[a][b] = 1;
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for(int j=1; j<=n; j++) {
			if(vis[j]) {
				++ans;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
