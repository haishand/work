#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<double> a(n), b(n);
	for(int i=0; i<n; i++) {
		int t;
		double l, r;
		cin >> t >> l >> r;
		switch(t) {
			case 2:
				r-=0.5;
				break;
			case 3:
				l+=0.5;
				break;
			case 4:
				r-=0.5;
				l+=0.5;
		}
		a[i] = l; b[i] = r;
	}

	int ans = 0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(max(a[i], a[j])<=min(b[i], b[j])) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
