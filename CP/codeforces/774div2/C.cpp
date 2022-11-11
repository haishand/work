#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

const ll maxn = 1e12;
typedef pair<ll, int> pli;

#define fi first
#define se second
#define mp make_pair

int dp[maxn+1];
ll solve(vector<pli>& pwnum, ll n, ll k) {
	if(n==0) {
		return k ;
	}

	ll ans = maxn;
	for(int i=0; i<=pwnum.size(); i++) {
		ll x = pwnum[i].fi;
		ll flag = pwnum[i].se;
		if(flag == 0 || n<x) continue;

		pwnum[i].se = 0;
		ans = min(ans, solve(pwnum, n-x, k+1));
		pwnum[i].se = 1;
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;

		vector<pli> pwnum;
		map<ll, int> mf;

		ll x=1;
		while(x<=n) {
			pwnum.push_back(mp(x, 1));
	//		cout << "pwoer x:" << x << endl;
			mf[x] = 1;
			x*=2;
		}

		//factorial
		x = 1;
		ll i = 1;
		while(x<=n) {
			if(mf.find(x) == mf.end()) {
				pwnum.push_back(mp(x, 1));
	//			cout << "fact x:" << x << endl;
			}
			++i;
			x*=i;
		}

		sort(pwnum.begin(), pwnum.end(), greater<pair<ll, int>>());

		ll ans = solve(pwnum, n, 0);
		cout <<  ((ans==maxn)?-1:ans) << endl;
	}
	return 0;
}
