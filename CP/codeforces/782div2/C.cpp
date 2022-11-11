#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define fi first
#define se second

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> x(n+1);
		for(int i=1; i<=n; i++) {
			cin >> x[i];
		}
		vector<int> dp(n+1, 0);
		dp[0] = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(dp[0]);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {

			}	
		}

	}
	return 0;
}
