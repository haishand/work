#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define fi first
#define se second

typedef pair<ll, ll> pll;
ll a[2][maxn];

pll dp[2];
int main() {
	int n;
	cin >> n;

	for(int i=0; i<2; i++) { 
		for(int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	dp[0].fi = dp[0].se = 0;
	for(int i=1; i<=n; i++) {
		dp[i%2].fi = max(dp[(i-1)%2].se + a[0][i], dp[(i-1)%2].fi);
		dp[i%2].se = max(dp[(i-1)%2].fi + a[1][i], dp[(i-1)%2].se);

	}
	cout << max(dp[n%2].fi, dp[n%2].se) << endl;
	return 0;
}
