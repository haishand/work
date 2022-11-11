#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
int main() {
	int n;
	cin >> n;
	char grid[n+1][n+1];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> grid[i][j];
		}
	}
	int dp[n+1][n+1];
	dp[1][1] = (grid[1][1]=='.');
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1 && j==1) continue;
			dp[i][j] = 0;
			if(grid[i][j] != '.') continue;
			if(grid[i-1][j] == '.') {
				dp[i][j] += dp[i-1][j];
			}
			dp[i][j]%=MOD;
			if(grid[i][j-1] == '.') {
				dp[i][j] += dp[i][j-1];
			}
			dp[i][j]%=MOD;
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}
