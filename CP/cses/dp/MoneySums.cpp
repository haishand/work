#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100;
const int maxval = 1e5;

int dp[maxn+1][maxval+1] = {0};
int main() {
	int n;
	cin >> n;
	vector<int> x(n+1);
	for(int i=1; i<=n; i++) {
		cin >> x[i];
	}
	dp[0][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int v=0; v<=maxval; v++) {
			dp[i][v] |= dp[i-1][v];
			if(v-x[i]>=0) {
				dp[i][v] |= dp[i-1][v-x[i]];
			}
		}
	}
	vector<int> ans;
	for(int v=1; v<=maxval; v++) {
		if(dp[n][v]) {
			ans.push_back(v);
		}
	}
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
