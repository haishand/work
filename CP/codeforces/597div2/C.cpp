#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

vector<ll> c(maxn, 0);

void pre_c() {
	c[0] = 0;
	c[1] = 1; c[2] = 2;
	for(int i=3; i<maxn; i++) {
		c[i] = c[i-1]+c[i-2];
		c[i] %= mod;
	}
}

int main() {
	pre_c();
	string s;
	cin >> s;
	int n = s.size();
	ll ans = 1;
	ll cn = 0, cu = 0;
	int nflag = 0, uflag = 0;
	for(int i=0; i<n; i++) {
		if(s[i] == 'm' || s[i] == 'w') {
			ans = 0;
			break;
		}
		if(s[i] == 'n') {
			uflag = 0;
			if(cu) {
				ans *=c[cu];
				cu = 0;
			}
			nflag = 1;
			++cn;
		}else if(s[i] == 'u') {
			nflag = 0;
			if(cn) {
				ans *= c[cn];
				cn = 0;
			}
			uflag = 1;
			++cu;
		}else {
			nflag = 0;
			uflag = 0;
			if(cn) {
				ans *= c[cn];
			}
			if(cu) {
				ans *= c[cu];
			}
			cn = 0;
			cu = 0;
		}
		ans %= mod;
	}
	if(cn) {
		ans *= c[cn];
	}
	if(cu) {
		ans *= c[cu];
	}
	ans %= mod;
	cout << ans << endl;
	return 0;
}
