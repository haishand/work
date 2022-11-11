#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll a, b, x;
	cin >> a >> b >> x;
	ll ans = b/x -a/x + (a%x==0);
	cout << ans << endl;
	return 0;
}
