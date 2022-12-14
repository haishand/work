#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxs = 1e6;
const int maxl = 1e5;

struct seq {
	int first, last;
	int asc = 0;
};

int main() {
	ll n;
	cin >> n;

	vector<struct seq> s(maxl);
	vector<int> vt;

	for(int i=0; i<n; i++) {
		int l;
		cin >> l;
		int mi = maxs;
		s[i].asc = 0;
		for(int j=0; j<l; j++) {
			int t;
			cin >> t;
			if(j==0) {
				s[i].first = t;
			}
			if(j==l-1) {
				s[i].last = t;
			}
			mi = min(mi, t);
			if(j>0 && t>mi) {
				s[i].asc = 1;
			}
		}
		if(s[i].asc == 0)
			vt.push_back(s[i].last);
	}

	sort(vt.begin(), vt.end());

	ll ans = n*n;
	for(int i=0; i<n; i++) {
		if(s[i].asc==0) {
			auto it = lower_bound(vt.begin(), vt.end(), s[i].first);			
			ans -= vt.end()-it;
		}
	}
	cout << ans << endl;

	return 0;
}
