#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n, m;
	cin >> n >> m;
	
	ll ans = 0;
	if(m<=n*2) {
		ans = m/2;
	}else {
		ans = n+(m-n*2)/4;
	}
	cout << ans << endl;
	return 0;
}
