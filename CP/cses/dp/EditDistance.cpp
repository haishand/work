#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5000;
const int maxm = 5000;

int dp[maxn+1][maxm+1];

int min3(int a, int b, int c) {
	return min(a, min(b, c));
}
int main() {
	int n, m;
	string s1, s2;
	cin >> s1 >> s2;
	n = s1.length(); m = s2.length();

	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(i) {
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			}
			if(j) {
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			}
			if(i && j) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(s1[i-1]!=s2[j-1]));
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
