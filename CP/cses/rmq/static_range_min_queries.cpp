#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 2e5+10;
const int maxm = 20;
const int mx = 1e9+10;

ll dp[maxn][maxm];

int main() {
	int n, q;
	cin >>n >> q;
	vector<ll> x(n+1, 0);
	for(int i=1; i<=n; i++) {
		cin >> x[i];
	}

	for(int i=0; i<=n; i++) {
		for(int j=0; (1<<j)<=n; j++) {
			dp[i][j] = mx;
			if(i>0 && j==0) {
				dp[i][j] = x[i];
			}
		}
	}
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i+(1<<j)-1<=n; i++) {
			dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}

	/*
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i<=n; i++) {
			printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
		}
	}
	*/
	for(int i=0; i<q; i++) {
		int a, b;
		cin >> a >> b;
		ll ans;
		int m = log2(b-a+1);
		ans = min(dp[a][m], dp[b-(1<<m)+1][m]);
//		printf("[%d, %d], [%d, %d]\n", a, m, b-(1<<m)+1, m);
		cout << ans << endl;
	}
	return 0;
}
