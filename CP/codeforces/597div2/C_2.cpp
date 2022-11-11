#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

vector<ll> dp(maxn, 0);

int main() {
	string s;
	cin >> s;
	int n = s.size();

	if(s.find('m') != string::npos || s.find('w') != string::npos) {
		cout << 0 << endl;
	}else {
		dp[0] = 1; dp[1] = 1;
		for(int i=2; i<=n; i++) {
			dp[i] = dp[i-1];
			if(s[i-1]==s[i-2] && (s[i-1] == 'n' || s[i-1] == 'u')) {
				dp[i] += dp[i-2];
			}
			dp[i] %= mod;
		}	
		cout << dp[n] << endl;
	}
	return 0;
}
