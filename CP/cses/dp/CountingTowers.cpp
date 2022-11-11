#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;
const int maxn = 1e6;

ll dp[2][maxn+1];
int main() {
	int t;
	cin >> t;
	
	dp[0][1] = 1; dp[1][1] = 1;
	for(int i=2; i<=maxn; i++) {
		dp[0][i] = (4*dp[0][i-1] + dp[1][i-1])%mod;
		dp[1][i] = (2*dp[1][i-1] + dp[0][i-1])%mod;
	}
	while(t--) {
		int n;
		cin >> n;

		cout << (dp[0][n] + dp[1][n])%mod << endl;
	}

	return 0;
}
