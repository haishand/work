#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5+10;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);	
	vector<ll> b(200);
	for(int i=0; i<n; i++) {
		cin >> a[i];
		++b[a[i]%200];
	}
	ll ans = 0;
	for(int i=0; i<200; i++) {
		ans += (b[i]*(b[i]-1))/2;
	}
	cout << ans << endl;
	return 0;
}
