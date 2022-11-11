#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 500;
const int maxsum = maxn*(maxn+1)/4;
const int mod = 1e9+7;

int main() {
	int n;
	cin >> n;
	vector<int> x(n+1);
	for(int i=1; i<=n; i++) {
		cin >> x[i];
	}

	/*
	// O(n^2)
	vector<int> dp(n+1, 1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(x[j]<x[i]) { 
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	cout << dp[n] << endl;
	*/
	vector<int> dp;
	for(int i=1; i<=n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), x[i]);
		if(it == dp.end()) {
			dp.push_back(x[i]);
		}else {
			*it = x[i];
		}
	}
	cout << dp.size() << endl;
	return 0;
}
