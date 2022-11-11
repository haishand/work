#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100;
const int maxval = 1e5;

int main() {
	int n;
	cin >> n;
	vector<int> x(n+1);
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	ll sum = 0;
	for(int i=1; i<=n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	dp[0][0] = 0;
	for(int l=n; l>0; l--) {
		for(int r=l; r<=n; r++) {
			if(l==r) {
				dp[l][r] = x[l];
			}else {
				dp[l][r] = max(x[l]-dp[l+1][r], x[r]-dp[l][r-1]);
			}
		}
	}
	cout << (dp[1][n] + sum)/2 << endl;
	return 0;
}
