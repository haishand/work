#include<bits/stdc++.h>
using namespace std;

// use the parity of i and n
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	deque<int> b;
	for(int i=0; i<n; i++) {
		if(i%2 != n%2) {
			b.push_front(a[i]);
		}else {
			b.push_back(a[i]);
		}
	}
	for(int e : b) {
		printf("%d ", e);
	}
	return 0;
}
