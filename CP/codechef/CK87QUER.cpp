#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e9;

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll y;
		cin >> y;
		ll ans = 0;
		for(int b=1; b<=700 && b<=y; b++) {
			ans += sqrt(y-b);
		}
		cout << ans << endl;
	}
	return 0;
}
