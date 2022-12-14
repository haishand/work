#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 1e8+1;

int main() {
	int n; 
	cin >> n;
	vector<int> c(n+1);
	vector<int> dp(8, maxn);
	for(int i=1; i<=n; i++) {
		string s;
		cin >> c[i] >> s;
		int m = 0;
		for(int j=0; j<s.size(); j++) {
			m += (1<<(s[j]-'A'));
		}
		dp[m] = min(dp[m], c[i]);
//		printf("%d: price = %d, vit = %d\n", i, c[i], m);
	}

	dp[0] = 0;
	for(int i=1; i<8; i++) {
		for(int j=0; j<=i; j++) {
			for(int k=0; k<=i; k++) {
//				printf("i=%d, j=%d, k=%d, (j | k)=%d\n", i, j, k, j | k);
				if((j | k) == i) {
					dp[i] = min(dp[i], dp[j] + dp[k]);
				}
			}
		}
//		printf("dp[%d]=%d\n", i, dp[i]);
	}

	if(dp[7] == maxn) {
		cout << -1 << endl;
	}else {
		cout << dp[7] << endl;
	}
	return 0;
}
