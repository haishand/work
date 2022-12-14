#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxint = 1e9+10;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int m;
		cin >> m;
		int a[3][m+1];
		ll sum[3][m+1];
		memset(sum, 0, sizeof(sum));
		for(int i=1; i<=2; i++) {
			for(int j=1; j<=m; j++) {
				cin >> a[i][j];
				sum[i][j] += sum[i][j-1]+a[i][j];
			}
		}
		ll ans = maxint;
		for(int col=1; col<=m; col++) {
			ll left = sum[2][col-1];
			ll right = sum[1][m]-sum[1][col];
//			printf("left=%lld, right=%lld\n", left, right);
			ans = min(ans, max(left, right));
		}
		cout << ans << endl;
	}
    return 0;
}
