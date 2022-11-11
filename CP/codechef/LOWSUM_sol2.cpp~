#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxK = 2e4;

int T, K, Q;

ll solve(vector<ll> &a, vector<ll> &b, int qu) {
	ll left = a[0]+b[0], right = a[K-1]+b[K-1];
	ll x;
	for(x = left; x<=right; x++) {
		ll ans = 0;
		for(int i=0; i<K; i++) {
			if(x-a[i]<b[0]) {
				break;
			}else if(x-a[i]>=b[K-1]) {
				ans += K;
			}else {
				auto it = upper_bound(b.begin(), b.end(), x-a[i]);
				ans += it-b.begin();
			}
		}
//		printf("x=%d, ans=%d\n", x, ans);
		if(ans >= qu) {
			return x;
		}
	}
	return x-1;
}

ll bsearch(vector<ll> &a, vector<ll> &b, ll low, ll high, int qu) {
	if(low <= high) {
		ll mid = (low+high)/2;
		int ans = 0;
		for(int i=0; i<K&&mid>a[i]; i++) {
			/*
			if(mid-a[i]<b[0]) {
				break;
			}else if(mid-a[i]>=b[K-1]) {
				ans += K;
			}else {
				auto it = upper_bound(b.begin(), b.end(), mid-a[i]);
				ans += it-b.begin();
			}
			*/
			int j=K-1;
			while(j>=0 && mid-a[i]<b[j]) {
				--j;
			}
			ans+=j+1;
		}
		if(ans>=qu) {
			ll t = bsearch(a, b, low, mid-1, qu);
//			printf("mid=%d, small=%d, ans=%d\n", mid, t, ans); 
			return min(mid, t);
		}else {
			return bsearch(a, b, mid+1, high, qu);
		}
	}
	return a[K-1]+b[K-1];
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
//	fastIO();
	cin >> T;
	while(T--) {
		cin >> K >> Q;
		
		vector<ll> a(K), b(K);
		for(int i=0; i<K; i++) {
		    scanf("%lld", &a[i]);
		}
		for(int i=0; i<K; i++) {
			scanf("%lld", &b[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		while(Q-->0) {
			int qu;
			cin >> qu;
//			scanf("%lld", &qu);
			
			ll low = a[0]+b[0];
			ll high = a[K-1]+b[K-1];
			ll ans = high;
			while(low<=high) {
				ll mid = (low+high)/2;
				int cnt = 0, j=K-1;
				for(int i=0; i<K&&mid>a[i]; i++) {
                    while(j>=0 && b[j]>mid-a[i]) j--;
                    cnt += j+1;
				}
				if(cnt>=qu) {
					ans = mid;
					high=mid-1;
				}else {
					low=mid+1;
				}
			}
			printf("%lld\n", ans);
//			cout << solve(a, b, qu) << endl;
//			printf("%lld\n", bsearch(a, b, a[0]+b[0], a[K-1]+b[K-1], qu));
//			cout << ans << endl;
		}
	}
	return 0;
}

