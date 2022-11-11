#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;
const int MOD = 1e9+7;

ll dp[N][10];

int main() {
	string s;
	cin >> s;

	string t = "chokudai";
	
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<s.size(); i++) {
		dp[i][0] = 1;
	}
	for(int i=1; i<=s.size(); i++) {
		for(int j=1; j<=t.size(); j++) {
			if(s[i-1] != t[j-1]) {
				dp[i][j] = dp[i-1][j];
			}else {
				dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[s.size()][t.size()] << endl;

	return 0;
}
