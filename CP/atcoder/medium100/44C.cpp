#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	vector<int> b(n);
	int i = 0, j = n-1, k = n-1;
	while(i<j) {
		b[i] = a[k];
		b[j] = a[k-1];
		++i; --j; k-=2;
	}
	if(k==0) {
		b[i] = a[k];
	}
	for(int i=0; i<n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
