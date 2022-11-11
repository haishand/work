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
	memset(dp, 0, sizeof(dp));
	for(int pos = 1; pos <=n; pos++) {
		for(int last = pos; last <= k; last++) {
			if(last == pos) {
				dp[pos][last] = max(dp[pos-1][last-1], abs(a[pos]-b[last])+abs(p-b[last]));
				continue;
			}
			dp[pos][last] = min(max(dp[pos-1][last-1], abs(a[pos]-b[last])+abs(p-b[last])), dp[pos][last-1]);
		}
	}
	int ans = maxint;
	for(int last=n; last<=k; last++) {
		ans = min(ans, dp[n][last]);
	}
	cout << ans << endl;
	return 0;
}
