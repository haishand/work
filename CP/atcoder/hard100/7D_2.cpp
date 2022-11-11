#include<bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<ll, ll> pii;

int main() {
	int n, m;
	cin >> n >> m;
	map<ll, ll, greater<ll>> mp;

	vector<ll> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<ll> b(m), c(m);
	for(int i=0; i<m; i++) {
		cin>>b[i]>>c[i];
	}

	for(int i=0; i<n; i++) {
		mp[a[i]]++;
	}
	for(int i=0; i<m; i++) {
		mp[c[i]] += b[i];
	}

	ll ans = 0;
	ll cnt = 0;
	for(auto i = mp.begin(); i!=mp.end(); i++) {
		if(cnt >= n) break;
		if(cnt + i->second <= n) {
			ans += (i->second) * (i->first);
			cnt += i->second;
		}else {
			ans += (n-cnt)*(i->first);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
