#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

void dfs(int v, vector<int>& vis, vector<vector<int>>& g) {
	vis[v] = 1;
	for(auto u : g[v]) {
		if(!vis[u]) {
			dfs(u, vis, g);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n+1);
		vector<int> vis(n+1);
//		g.resize(n+1);
//		vis.resize(n+1);
		vector<int> a(n), b(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		for(int i=0; i<n; i++) {
			cin >> b[i];
		}
		for(int i=0; i<n; i++) {
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		ll ans = 1;
		for(int v=1; v<=n; v++) {
			if(!vis[v]) {
//				printf("v=%d\n", v);
				ans *= 2;
				ans %= MOD;
				dfs(v, vis, g);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
