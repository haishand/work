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

		ll ans = 0;
		vector<int> ones;
		vector<bool> chained(n+1, 0);

		for(int i=1; i<=n; i++) {
			if(!chained[i]) {
				ones.clear();
				int cur_ones = 0;
				for(int j=i; j<=n; j+=e) {
					if((a[j]!=1 && !prime[a[j]]) || chained[j]) {
						break;
					}
					chained[j] = 1;
					if(a[j] == 1) {
						++cur_ones;
					}else {
						ones.push_back(cur_ones);
						cur_ones = 0;
					}
				}

				if(ones.size() == 0) continue;
				ones.push_back(cur_ones);
				for(int j=0; j<ones.size(); j++) {
					ans += ones[j];
					if(j>0 && j<ones.size()-1) {
						ans += ones[j];
					}
					if(j<ones.size()-1) {
						ans += (ll)(ones[j])*(ll)(ones[j+1]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
