#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	if(a[1] == 0) {
		fill(dp[1].begin(), dp[1].end(), 1);
	}else {
		dp[1][a[1]] = 1;
	}
	for(int i=2; i<=n; i++) {
		if(a[i] == 0) {
			for(int j=1; j<=m; j++) {
				dp[i][j] = 0;
				for(int k: {j-1, j, j+1}) {
					if(k>0 && k<=m) {
						dp[i][j] += dp[i-1][k];
						dp[i][j] %= MOD;
					}
				}
//				printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
			}
		}else {
			for(int j : {a[i]-1, a[i], a[i]+1}) {
				if(j>0 && j<=m) {
					dp[i][a[i]] += dp[i-1][j];
					dp[i][a[i]] %= MOD;
				}
			}
//			printf("dp[%d][%d]=%d\n", i, a[i], dp[i][a[i]]);
		}
	}
	int ans = 0;
	for(int j=1; j<=m; j++) {
		ans += dp[n][j];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
