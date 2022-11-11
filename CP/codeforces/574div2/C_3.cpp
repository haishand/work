#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define first fi;
#define second se;

typedef pair<ll, ll> pll;
ll a[2][maxn];

ll dp[3][2];
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
		ll ma0 = dp[0][(i-1)%2];
		ll ma1 = dp[1][(i-1)%2];
		ll ma2 = dp[2][(i-1)%2];

		dp[0][i%2] = max(ma1+a[1][i], ma2+a[1][i]); 
		dp[1][i%2] = max(ma0+a[0][i], ma2+a[0][i]);
		dp[2][i%2] = max(ma0, ma1);
	}
	cout << max(dp[0][n%2], dp[1][n%2]) << endl;
	return 0;
}
