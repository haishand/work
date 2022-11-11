#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 500;
const int maxsum = maxn*(maxn+1)/4;
const int mod = 1e9+7;

ll dp[maxn+1][maxsum+1] = {0};
int main() {
	int n;
	cin >> n;
	int sum = n*(n+1)/2;
	if(sum%2) {
		cout << 0 << endl;
	}else {

		dp[0][0] = 1;
		for(int i=1; i<n; i++) {
			for(int j=0; j<=sum/2; j++) {
				dp[i][j] = dp[i-1][j];
				if(j-i>=0) {
					dp[i][j] += dp[i-1][j-i]; 	
					dp[i][j] %= mod;		
				}
			}
		}

		cout << dp[n-1][sum/2] << endl;
	}
	return 0;
}
