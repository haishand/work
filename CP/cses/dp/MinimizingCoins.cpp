#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 1e6+10;
const int INF = 0x3f3f3f3f;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> a(MAXN);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector<int> dp(MAXN, INF);
	dp[0] = 0;
	for(int i=0; i<=x; i++) {
		for(int j=0; j<n; j++) {
			if(i-a[j]<0) continue;
			dp[i] = min(dp[i], dp[i-a[j]]+1);
		}
	}
	cout << (dp[x]<INF?dp[x]:-1) << endl;
	return 0;
}
