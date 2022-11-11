#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

ll comb(int n, int m) {
	if(n==0 || n==1 || (n==m)) {
		return 1;
	}
	if(m==1) {
		return n;
	}
	return comb(n-1, m-1) + comb(n-1, m);
}

ll c[100][100];
ll pre_comb(int n, int m) {
	c[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(i==j) {
				c[i][j] = 1;
			}else if(j==1) {
				c[i][j] = i; 
			}else {
				c[i][j] = c[i-1][j-1] + c[i-1][j];
			}
		}
	}
	return c[n][m];
}

ll fastpow(int n, int p) {
	ll ans = 1;
	if(p==0) return 1;
	if(p%2) {
		ans *= n;
	}
	ans *= fastpow(n*n, p/2);
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	// dp[i][0]: the positive number of subsegment which end of i
	// dp[i][1]: the negative number of subsegment which end of i
	ll dp[n+1][2]={0};
	dp[0][0] = 0; dp[0][1] = 0;
	for(int i=1; i<=n; i++) {
		if(a[i]>0) {
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1];
		}else {
			dp[i][0] = dp[i-1][1];
			dp[i][1] = dp[i-1][0]+1;
		}
	}
	ll ne = 0, po = 0;
	for(int i=1; i<=n; i++) {
		po += dp[i][0];
		ne += dp[i][1];
	}
	cout << ne << " " << po << endl;

	return 0;
}
