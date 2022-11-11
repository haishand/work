#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int count(int val, const vector<int>& v, int low, int high) {
	if(low>high) return 0;
	int le = lower_bound(v.begin()+low, v.begin()+high, val) - v.begin();
	int ri = upper_bound(v.begin()+low, v.begin()+high, val) - v.begin();
//	printf("from %d to %d to search %d, le=%d, ri=%d\n", low, high, val, le, ri);
	/*
	int tlow = low;
	int thigh = high;
	while(low<=high) {
		int mid = (low+high)/2;
		if(v[mid]<val) {
			low = mid+1;
		}else {
			high = mid -1;
		}
	}
	int le = low;

	low = tlow, high = thigh;
	while(low<=high) {
		int mid = (low+high)/2;
		if(v[mid]<=val) {
			low = mid+1;
		}else {
			high = mid -1;
		}
	}
	int ri = low;
	*/

//	printf("from %d to %d to search %d, le=%d, ri=%d\n", tlow, thigh, val, le, ri);
	return abs(ri - le);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> c;
		ll sum = 0;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
			c[a[i]]++;
		}
		sort(a.begin(), a.end());
		ll ans = 0;
		if(2*sum%n == 0) {
			ll pairsum = 2*sum/n;
			for(int i=0; i<n; i++) {
				int another = pairsum-a[i];
				ll cc = c[another] - (another==a[i]);
//				printf("a[%d]=%d, cc=%d\n", i, a[i], cc);
				ans += cc;
//				ans += count(another, a, i+1, n);
			}
		}
		cout << ans/2 << endl;
	}
    return 0;
}
