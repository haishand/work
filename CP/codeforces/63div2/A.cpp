#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

int main() {
	int n;
	cin >> n;
	ar<int, 3> a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int ans = 1;
	for(int i=0; i<3; i++) {
		int sum = 0;
		for(int j=0; j<n; j++) {
			sum += a[j][i];
		}
		if(sum!=0) {
			ans = 0;
			break;
		}
	}
	if(ans) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}
	return 0;
}
