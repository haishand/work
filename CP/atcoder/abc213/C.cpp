#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int h, w;
	int n;
	cin >>h >> w >> n;
	vector<int> a(n), ta(n);
	vector<int> b(n), tb(n);
	map<int, int> ma, mb;
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = ta[i] =  x;
		b[i] = tb[i] = y;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	for(int i=0; i<a.size(); i++) {
		ma[a[i]] = i+1;
	}
	for(int i=0; i<b.size(); i++) {
		mb[b[i]] = i+1;
	}
	for(int i=0; i<n; i++) {
		cout << ma[ta[i]] << " " << mb[tb[i]] << endl;
	}

	return 0;
}
