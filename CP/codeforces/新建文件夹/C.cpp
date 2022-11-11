#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int count(int val, const vector<int>& v, int low, int high) {
	int le = lower_bound(v.begin()+low, v.begin()+high, val);
	int ri = upper_bound(v.begin()+low, v.begin()+high, val);
	if(v[le]==val) {
		return ri-le;
	}else{
		return 0;
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		lower_bound(a+1, a+2, a[0]);
		sort(a.begin(), a.end());
		int ans = 0;
		if(2*sum%n == 0) {
			int pairsum = 2*sum/n;
			for(int i=0; i<n; i++) {
				int another = pairsum - a[i];
				ans = count(another, a, i, n-1);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
