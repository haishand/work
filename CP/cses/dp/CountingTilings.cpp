#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int mxN = 10;
const int mxM = 1000;
const int mod = 1e9+7;

int n, m;
int dp[mxM+1][1<<(mxN+1)];

void generate_masks(int cur, int i, int next, vector<int>& next_masks) {
	if(i==n+1) {
		next_masks.push_back(next);
		return;
	}
	
	if((cur & (1<<i)) != 0) {
		generate_masks(cur, i+1, next, next_masks);
	}

	// place vertically
	if(i!=n) {
		if((cur & (1<<i)) == 0 && (cur & (1<<(i+1))) == 0) {
			generate_masks(cur, i+2, next, next_masks);
		}
	}

	// place horinzontally
	if((cur & (1<<i)) == 0) {
		generate_masks(cur, i+1, next+(1<<i), next_masks);
	}
}

int solve(int col, int mask) {
	if(col == m+1) {
		if(mask == 0) {
			return 1;
		}
		return 0;
	}
	if(dp[col][mask] != -1) {
		return dp[col][mask];
	}

	ll ans = 0;
	vector<int> next_masks;
	generate_masks(mask, 1, 0, next_masks);
	for(int mask : next_masks) {
		ans += solve(col+1, mask);
		ans %= mod;
	}
	return dp[col][mask] = ans;
}

int main() {
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 0);
	return 0;
}
