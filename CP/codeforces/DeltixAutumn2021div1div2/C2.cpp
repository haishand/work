#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxa = 1e6;

int used[maxa+1];
int prime[maxa+1];

void pre_calc() {
	memset(used, 0, sizeof(used));
	memset(prime, 0, sizeof(prime));
	for(int i=2; i<=maxa; i++) {
		if(!used[i]) {
			prime[i] = 1;
			for(int j=i; j<=maxa; j+=i) {
				used[j] = 1;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	pre_calc();
	
	while(t--) {
		int n, e;
		cin >> n >> e;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}

		vector<int> l(n+1, 0), r(n+1, 0);
		ll ans = 0;
		for(int i=n; i>0; i--) {
			if(a[i] == 1) {
				if(i+e<=n){
					r[i] = r[i+e];
				}
				++r[i];
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i] == 1) {
				if(i-e>=0) {
					l[i] = l[i-e];
				}
				++l[i];
			}else if(prime[a[i]]) {
				ans += (ll)(i-e>0?l[i-e]+1:1)*(ll)(i+e<=n?r[i+e]+1:1)-1;
//				printf("i=%d, l[i-e]=%d, r[i+e]=%d\n", i, l[i-e], r[i+e]); 
			}
		}
		cout << ans << endl;
	}
	return 0;
}
