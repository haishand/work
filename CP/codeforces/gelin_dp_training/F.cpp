#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1001;
const int maxk = 5;

ll cm[maxn][maxk];

void calc_cm() {
	cm[0][0] = 1;
	for(int i=1; i<maxn; i++) {
		cm[i][0] = 1;
		cm[i][1] = i;
	}
	for(int i=1; i<maxn; i++) {
		for(int j=1; j<maxk; j++) {
			cm[i][j] = cm[i-1][j] + cm[i-1][j-1];
		}
	}
}

int main() {
	int n, k;
	calc_cm();
	cin >> n >> k;

	vector<ll> f(n+1, 0);
	f[0] = 1; f[1] = 0; f[2] = 1;
	for(int i=3; i<=n; i++) {
		f[i] = (i-1)*(f[i-1]+f[i-2]);
	}
	ll ans = 0;
	for(int j=0; j<=k; j++) {
		ans += cm[n][j]*f[j];
	}

	cout << ans << endl;
	return 0;
}
