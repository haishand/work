#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	vector<int> c(m), d(m);
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i=0; i<m; i++) {
		cin >> c[i] >> d[i];
	}

	for(int i=0; i<n; i++) {
		int dist = abs(a[i]-c[0])+abs(b[i]-d[0]);
		int idx = 0;
		for(int j=1; j<m; j++) {
			int t = abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(t<dist) {
				dist = t;
				idx = j;
			}
		}
		cout << idx+1 << endl;
	}
    return 0;
}
