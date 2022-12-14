#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

ll a[2][maxn];
ll dp[3][maxn];
int main() {
	int n;
	cin >> n;

	for(int i=0; i<2; i++) { 
		for(int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0;
	for(int i=1; i<=n; i++) {
		ll ma0 = dp[0][i-1];
		ll ma1 = dp[1][i-1];
		ll ma2 = dp[2][i-1];

		dp[0][i] = max(ma1+a[1][i], ma2+a[1][i]); 
		dp[1][i] = max(ma0+a[0][i], ma2+a[0][i]);
		dp[2][i] = max(ma0, ma1);
	}
	cout << max(dp[0][n], dp[1][n]) << endl;
	return 0;
}
