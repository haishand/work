#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, X, B, C;
#define vv vector<pair<int, pair<ll, ll>>>

int can_reach(ll sz, vv& v) {
	for(int i=0; i<v.size(); i++) {
		int x = v[i].first;
		if(v[i].second.second != -1) {
			if(v[i].second.first<=sz) {
				sz += v[i].second.second;	
			}
		}else {
			sz -= v[i].second.first;
		}
		if(sz<=0) return 0;
	}
	return 1;
}
ll mxSz = 0;

ll bsearch(ll low, ll high, vv& v){
	ll ans = mxSz;
	if(low <= high) {
		ll mid = (low + high)/2;
		if(can_reach(mid, v)) {
			ans = mid;
			return min(ans, bsearch(low, mid-1, v));
		}else {
			return bsearch(mid+1, high, v);
		}
	}
	return ans;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &X);
		scanf("%d", &B);
		ll size = 1;

		vv v;
		for(int i=0; i<B; i++) {
			int x;
			ll y;
			scanf("%d %lld", &x, &y);
			size += y;
			v.push_back({x, {y, -1}});
		}
		scanf("%d", &C);
		for(int i=0; i<C; i++) {
			int p;
			ll q, r;
			scanf("%d %lld %lld", &p, &q, &r);
			v.push_back({p, {q, r}});
		}

		sort(v.begin(), v.end());

		mxSz = size;
		ll ans = bsearch(1, size, v);
		cout << ans << endl;
	}
	return 0;
}
