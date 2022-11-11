#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN = 2e5;

ar<int, 3> a[mxN];

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i][1] >> a[i][0] >> a[i][2];
	}
	sort(a, a+n);

	/*
	// O(n^2)
	vector<ll> dp(mxN);
	ll ans = 0;
	for(int i=0; i<n; i++) {
		dp[i] = a[i][2];
		for(int j=0; j<i; j++) {
			if(a[j][0]<a[i][1]) {
				dp[i] = max(dp[i], dp[j]+a[i][2]);
			}
		}
		ans = max(ans, dp[i]);
	}
	*/

	ll ans = 0;
	set<ar<ll, 2>> dp;
	dp.insert({0, 0});
	for(int i=0; i<n; i++) {
		auto it = dp.lower_bound({a[i][1]});
		--it;
		ans = max(ans, (*it)[1]+a[i][2]);
		dp.insert({a[i][0], ans});
	}
	cout << ans << endl;
	return 0;
}
