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
	for(int pos = 0; pos <=n;  pos++) {
		for(int last = 0; last<=k; last++) {
			dp[pos][last] = maxint;
		}
	}
	dp[0][0] = 0;
	for(int pos = 0; pos <n; pos++) {
		for(int last = 0; last<=k; last++) {
			dp[pos][last+1] = min(dp[pos][last+1], dp[pos][last]);
			if(last<k) {
				dp[pos+1][last+1] = min(dp[pos+1][last+1], max(dp[pos][last], abs(a[pos+1]-b[last+1])+abs(p-b[last+1])));
			}
		}
	}
	int ans = maxint;
	for(int last = 1; last<=k; last++) {
		printf("dp[%d][%d]=%d\n", n, last, dp[n][last]);
		ans = min(ans, dp[n][last]);
	}
	cout << ans << endl;
	return 0;
}
