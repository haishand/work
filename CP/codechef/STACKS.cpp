#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}

		vector<int> b;
		b.push_back(a[0]);
		for(int i=1; i<n; i++) {
			auto it = upper_bound(b.begin(), b.end(), a[i]);
			if(it == b.end()) {
				b.push_back(a[i]);
			}else {
				*it = a[i];
			}
//			printf("b.back()=%d\n", b.back());
		}
		cout << b.size(); 
		for(int i=0; i<b.size(); i++) {
			cout << " " << b[i];
		}
		cout << endl;
	}
	return 0;
}
