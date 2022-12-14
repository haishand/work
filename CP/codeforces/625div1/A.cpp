#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> b(n+1);
	vector<ll> dp(n+1, 0);
	for(int i=1; i<=n; i++) {
		cin >> b[i];
		dp[i] = b[i];
	}

	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if((j-i) == (b[j]-b[i])) {
				dp[j] = max(dp[j], dp[i] + b[j]);
			}
		}
	}

	ll ans = 0;
	for(int i=1; i<=n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
    return 0;
}
