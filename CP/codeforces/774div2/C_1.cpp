#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const ll maxn = 1e12;
typedef pair<ll, int> pli;

#define fi first
#define se second
#define mp make_pair

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;

		vector<ll> fact(14);
		ll f = 1;
		ll i = 1;
		ll cnt = 0;
		while(f<=maxn) {
			fact[cnt++] = f;
			f *= ++i;
		}
		ll ans = maxn;
		for(int i=0; i<=(1<<14); i++) {
			ll tmp = n;
			ll cnt = 0;
			for(int j=0; j<14; j++) {
				if(tmp<fact[j]) break;
				if((i>>j)&1) {
					tmp -= fact[j];
					++cnt;
				}
			}
			ans = min(ans, cnt + __builtin_popcountll(tmp));
		}
		cout << ans << endl;
	}
	return 0;
}
