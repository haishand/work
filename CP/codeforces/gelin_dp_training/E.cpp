#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e3+10;
const int maxk = 2e3+10;
const int maxint = 0x7fffffff;


int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> a(n+1), b(k+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i=1; i<=k; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());

	int dp[maxn][maxk];
	dp[0][0] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=k; j++) {
			if(i==j) {
				dp[i][j] = max(dp[i-1][j-1], abs(a[i]-b[j])+abs(p-b[j]));
				continue;
			}
			dp[i][j] = min(dp[i][j-1], max(dp[i-1][j-1], abs(a[i]-b[j])+abs(p-b[j])));
		}
	}
	int ans = maxint;
	for(int j=n; j<=k; j++) {
		ans = min(ans, dp[n][j]);
	}
	cout << ans << endl;
	return 0;
}
