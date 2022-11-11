#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 110;
const int MAXX = 1e6+10;

vector<int> dp(MAXX);
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> c(MAXN);
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}

	dp[0] = 1;
	for(int i=0; i<=x; i++) {
		for(int j=0; j<n; j++) {
			if(i-c[j]>=0) {
				dp[i] += dp[i-c[j]];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[x] << endl;
	return 0;
}
