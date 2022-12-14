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
	int j = 0;
	for(int i=0; i<n; i=j) {
		if(s[i] == 'm' || s[i] == 'w') {
			ans = 0;
			break;
		}
		j = i+1;
		while((j<n) && s[j]==s[i] && (s[j] == 'n' || s[j] == 'u')) {
			++j;
		}
//		printf("i=%d, j=%d\n", i, j);
		ans *= c[j-i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
