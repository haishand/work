#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e3+10;
const int maxk = 2e3+10;
const int maxint = 0x7fffffff;


int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> a(n), b(k);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i=0; i<k; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());

	int dp[k+1][n+1];
	for(int i=0; i<=k; i++) {
		for(int j=0; j<=n; j++) {
			dp[i][j] = maxint;
		}
	}
	dp[0][0] = 0;
	for(int i=0; i<k; i++) {
		for(int j=0; j<=n; j++) {
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if(j<n) {
				dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j]-b[i])+abs(p-b[i])));
			}
		}
	}
	cout << dp[k][n] << endl;
	return 0;
}
