#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const ll maxn = 1e12;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair

int get_first_bit(ll n) {
	return 64-__builtin_clzll(n)-1;
}
int get_bit_count(ll n) {
	return __builtin_popcountll(n);
}
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

		vector<pll> fact_sum((1<<14)+1);
		fact_sum[0] = {0, 0};
		for(ll i=1; i<=(1<<14); i++) {
			auto first_bit = get_first_bit(i);
			fact_sum[i].first += fact_sum[i^(1<<first_bit)].first + fact[first_bit]; 
			fact_sum[i].second = get_bit_count(i);
		}

		ll ans = maxn;
		for(auto i: fact_sum) {
			ans = min(ans, i.second + get_bit_count(n-i.first));
		}
		cout << ans << endl;
	}
	return 0;
}
