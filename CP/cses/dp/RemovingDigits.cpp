#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6+10;
const int INF = 0x3f3f3f3f;
int dp[MAXN];

int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	for(int i=1; i<=n; i++) {
		dp[i] = INF;
		int t = i;
		while(t) {
			int a = t%10;
			dp[i] = min(dp[i], dp[i-a]+1);	
			t /= 10;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
