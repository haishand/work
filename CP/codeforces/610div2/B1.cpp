#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxv = 2e9;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		vector<int> dp(n+1, 2e9);
		dp[0] = 0;
		for(int i=1; i<=n; i++) {
			dp[i] = min(dp[i], dp[i-1] + a[i-1]);
			if(i-k>=0) {
				dp[i] = min(dp[i], dp[i-k]+a[i-1]);
			}
		}

		for(int i=n; i>=0; i--) {
			if(dp[i]<=p) {
				cout << i << endl;
				break;
			}
		}

	}
	
	return 0;
}
