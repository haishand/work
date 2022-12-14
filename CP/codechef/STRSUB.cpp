#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bsearch(int s, int low, int high, int k, vector<int>& sum0, vector<int>& sum1) {
	int ans = s;
	if(low<=high) {
		int mid = (low+high)/2;
		int c0 = sum0[mid] - sum0[s-1];
		int c1 = sum1[mid] - sum1[s-1];
		if(max(c0, c1)<=k) {
			ans = mid;
			return max(ans, bsearch(s, mid+1, high, k, sum0, sum1));
		}else {
			return bsearch(s, low,  mid-1, k, sum0, sum1);
		}
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k, q;
		cin >> n >> k >> q;
		string s;
		cin >> s;
		vector<int> sum0(n+1), sum1(n+1);
		sum0[0] = sum1[0] = 0;
		for(int i=1; i<=n; i++) {
			sum0[i] = sum0[i-1] + (s[i-1]=='0');
			sum1[i] = sum1[i-1] + (s[i-1]=='1');
		}

		vector<int> far(n+1, 0);
		vector<ll> sfar(n+1, 0);
		for(int i=1; i<=n; i++) {
			far[i] = bsearch(i, i, n, k, sum0, sum1);
			sfar[i] = sfar[i-1]+far[i]-i+1;
		}
		/*
		for(int i=1; i<=n; i++) {
			printf("far[%d]=%d\n", i, far[i]);
		}
		*/
		while(q--) {
			int left, right;
			cin >> left >> right;
			if(left>right) {
				swap(left, right);
			}
			int le = left, ri = right;
			int j = left-1;
			while(le<=ri) {
				int mm = (le+ri)/2;
				if(far[mm]<=right) {
					j=mm;
					le = mm+1;
				}else {
					ri = mm-1;
				}
			}
//			printf("j=%d\n", j);
			ll ans = sfar[j]-sfar[left-1];
			ans += (1LL)*(right-j)*(right-j+1)/2;
			/*
			for(int i=left; i<=right; i++) {
				ans += min(right, far[i])-i+1;
			}
			*/
			cout << ans << endl;

		}
	}
	return 0;
}
