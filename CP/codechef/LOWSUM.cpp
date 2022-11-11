#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// too large memory allocation, so runtime error (other)
int main() {
	int t;
	cin >> t;
	while(t--) {
		int k, q;
		cin >> k >> q;
		vector<ll> a(k), b(k), c;
		for(int i=0; i<k; i++) {
			cin >> a[i];
		}
		for(int i=0; i<k; i++) {
			cin >> b[i];
		}
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for(int i=0; i<min(k, 10000); i++) {
			for(int j=0; j<min(k, 10000/(i+1)); j++) {
				c.push_back(a[i]+b[j]);
			}
		}

		sort(c.begin(), c.end());

		for(int i=0; i<q; i++) {
			int qr;
			cin >> qr;
			cout << c[qr-1] << endl;
		}
		
	}
	return 0;
}

