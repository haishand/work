#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;
const int maxm = 1e3+10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int squa[maxn][maxm];
int vis[maxn][maxm];
void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(squa[nx][ny] && !vis[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
int main() {
	memset(squa, 0, sizeof(squa));
	memset(vis, 0, sizeof(vis));
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			char c;
			cin >> c;
			squa[i][j] = 0;
			if(c=='.') {
				squa[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for(int x=1; x<=n; x++) {
		for(int y=1; y<=m; y++) {
			if(!vis[x][y] && squa[x][y]) {
				dfs(x, y);
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
