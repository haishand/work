#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+10;
int main() {
	int N;
	cin >> N;
	vector<int> a(MAXN);
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}

	/*
	// first solution
	int ans = 1;
	int delta = 0;
	for(int i=0; i<N-1; i++) {
		int ndelta;
		if(a[i]<a[i+1]) {
			ndelta = 1;
		}else if(a[i]>a[i+1]) {
			ndelta = -1;
		}else {
			ndelta = 0;
		}

		if(delta && ndelta && delta != ndelta) {
			++ans;
			delta = 0;
		}else if(!delta) {
			delta = ndelta;
		}
	}
	*/

	int ans = 0;
	for(int i=0; i<N; i++) {
		while(i<N-1 && a[i] == a[i+1]) ++i;
		if(a[i]<a[i+1]) {
			while(i<N-1 && a[i]<=a[i+1]) ++i;	
		}else if(a[i]>a[i+1]) {
			while(i<N-1 && a[i]>=a[i+1]) ++i;
		}
		++ans;
	}
	cout << ans << endl;
	return 0;
}
