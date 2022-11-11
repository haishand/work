#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int mod = 1e9;
const int maxn = 1e3;
const int maxk = maxn;

ll c[maxn][maxk];

int main() {
	int t;
	cin >> t;
	c[0][0] = 1;
	c[1][0] = 1; c[1][1] = 1;
	for(int k=2; k<maxn; k++) {
		for(int i=1; i<k; i++) {
			c[k][i] = (c[k-1][i-1]+c[k-1][i])%mod;
		}
		c[k][0] = c[k][k] = 1;
	}
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << c[n-1+k][n-1] << endl;
	}
	return 0;
}
