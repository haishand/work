#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[20][10][2][2];
ll solve(string& s, int n, int x, int tight, int lz) {
	if(n==0) {
		return 1;
	}

	if(dp[n][x][tight][lz]!=-1) {
		return dp[n][x][tight][lz];
	}
	int lb = 0;
	int ub = tight?s[s.length()-n]-'0':9;
	
	ll ans = 0;
	for(int d=lb; d<=ub; d++) {
		if(d == x && lz == 0) {
			continue;
		}
		ans += solve(s, n-1, d, tight&(d==ub), lz&(d==0));
	}
	return dp[n][x][tight][lz] = ans;
}

int main() {
	ll a, b;
	cin >> a >> b;
	string A = to_string(a-1);
	string B = to_string(b);
	int na = A.length();
	int nb = B.length();

	memset(dp, -1, sizeof(dp));
	ll ans1 = solve(B, nb, -1, 1, 1);

	memset(dp, -1, sizeof(dp));
	ll ans2 = solve(A, na, -1, 1, 1);

	cout << ans1 - ans2 << endl;
	return 0;
}
