#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 1e6+10;

ll dp[MAXN];
int main() {
	int n;
	cin >> n;

	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=min(6,i); j++) {
			dp[i] += dp[i-j];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
