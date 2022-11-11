#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

ll a[2][maxn];
ll dp[3][maxn];
int main() {
	int n;
	cin >> n;

	for(int i=0; i<2; i++) { 
		for(int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	priority_queue<ll> pq[3];
	dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0;
	pq[0].push(0);
	pq[1].push(0);
	pq[2].push(0);
	for(int i=1; i<=n; i++) {
		ll ma0 = pq[0].top(); 
		ll ma1 = pq[1].top(); 
		ll ma2 =pq[2].top();

//		dp[0][i] = max(ma1+a[1][i], max(ma2+a[1][i], a[1][i])); 
//		dp[1][i] = max(ma0+a[0][i], max(ma2+a[0][i], a[0][i]));
		dp[0][i] = max(ma1+a[1][i], ma2+a[1][i]); 
		dp[1][i] = max(ma0+a[0][i], ma2+a[0][i]);
		dp[2][i] = max(ma0, ma1);

		pq[0].push(dp[0][i]);
		pq[1].push(dp[1][i]);
		pq[2].push(dp[2][i]);

	}
	cout << max(dp[0][n], dp[1][n]) << endl;
	return 0;
}
