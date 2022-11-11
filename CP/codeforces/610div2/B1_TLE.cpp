#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxdp = 2e9;

int dp[3][maxdp+1] = {0};

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
		memset(dp, 0, sizeof(dp));
		dp[0][0]  = 0;
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=p; j++) {
				if(i-1>=0) {
					dp[i%3][j] = max(dp[i%3][j], dp[(i-1)%3][j]);
					if(j-a[i-1]>=0) {
						dp[i%3][j] = max(dp[i%3][j], dp[(i-1)%3][j-a[i-1]]+1);
					}
				}
				if(i-2>=0 && (j-a[i-1]>=0)) {
					dp[i%3][j] = max(dp[i%3][j], dp[(i-2)%3][j-a[i-1]]+2);
				}
//				printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
			}
		}
		
		int ans = 0;
		for(int j=a[0]; j<=p; j++) {
			ans = max(ans, dp[n%3][j]);
		}
		cout << ans << endl;
	}
	return 0;
}
