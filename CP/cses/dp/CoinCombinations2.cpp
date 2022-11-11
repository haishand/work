#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 110;
const int MAXX = 1e6+10;

int dp[MAXN][MAXX];
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> c(n+1);
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
//	sort(c.begin(), c.end());
	dp[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=x; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-c[i]>=0) {
				dp[i][j] += dp[i][j-c[i]];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n][x] << endl;
	/*
	dp[0][0] = 1;
	for(int i=0; i<=x; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=0; k<=n; k++) {
				if(i-c[j]>=0 && c[k]<=c[j]) {
					dp[i][j] += dp[i-c[j]][k];
					dp[i][j] %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	for(int i=0; i<=n; i++) {
		ans += dp[x][i];
		ans %= MOD;
	}
	cout << ans << endl;
	*/
	return 0;
}
