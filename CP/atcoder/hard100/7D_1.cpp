#include<bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<ll, ll> pii;

bool mycomp(pii& a, pii& b) {
	return a.second>b.second;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pii> mix;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		mix.push_back(make_pair(1, a[i]));
	}

	vector<pii> bc(m);
	for(int i=0; i<m; i++) {
		cin >> bc[i].first >> bc[i].second;
	}
	sort(bc.begin(), bc.end(), mycomp);

	int s = 0;
	for(int i=0; s<n && i<m; i++) {
		s += bc[i].first;
		mix.push_back(make_pair(bc[i].first, bc[i].second));
	}

	sort(mix.begin(), mix.end(), mycomp);
	ll ans = 0;
	for(int i=0; i<mix.size(); i++) {
		if(n>=mix[i].first) {
			ans += mix[i].first*mix[i].second;
			n-=mix[i].first;
		}else {
			ans += n*mix[i].second;
			n-=n;
		}
		if(n==0) break;
	}
	cout << ans << endl;
	return 0;
}
