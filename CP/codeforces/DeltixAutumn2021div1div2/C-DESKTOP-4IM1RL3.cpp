#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5;

int used[maxn+1];
int prime[maxn+1];

void pre_calc() {
	memset(used, 0, sizeof(used));
	memset(prime, 0, sizeof(prime));
	for(int i=2; i<=maxn; i++) {
		if(!used[i]) {
			prime[i] = 1;
			for(int j=i; j<=maxn; j+=i) {
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
		ll ans = 0;
		for(int i=1; i<=n; i++) {
			int one = 0;
			int np = 0;
			int len = 0;
			for(int j=i; j<=n; j+=e) {
				++len;
				if(prime[a[j]]) {
					++np;
				}
				if(a[j] == 1) {
					++one;
				}
				if(np==1 && one>=1 && (np+one)==len) {
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
