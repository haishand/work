#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
//int dp[1001][100001];
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> h(n+1);
	for(int i=1; i<=n; i++) {
		cin >> h[i];
	}
	vector<int> s(n+1);
	for(int i=1; i<=n; i++) {
		cin >> s[i];
	}

	int dp[n+1][x+1] = {};
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=x; j++) {
			printf("dp[%d][%d]=%d\t", i, j, dp[i][j]);
		}
		printf("\n");
	}
	dp[0][0] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=x; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-h[i]>=0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]]+s[i]);
			}
		}
	}
	int ans = 0;
	for(int j=0; j<=x; j++) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans << endl;
	return 0;
}
