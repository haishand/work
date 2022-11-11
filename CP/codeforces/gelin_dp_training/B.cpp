#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int avail[26] = {0};
	for(int i=0; i<k; i++) {
		char c;
		cin >> c;
		avail[c-'a'] = 1;
	}

	ll ans = 0;
	vector<int> dp(n+1);
	dp[0] = 0;
	for(int i=1; i<=n; i++) {
		if(avail[s[i-1]-'a']) {
			dp[i] = dp[i-1] + 1;
		}else {
			dp[i] = 0;
		}
		ans += dp[i];
	}
	
	cout << ans << endl;
	return 0;
}
