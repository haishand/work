#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	string s;
	cin >>  s;
	int n = s.length();
	ll ans  = 0;
	int mad = -1;
	int miu = n;
	for(int i=0; i<n; i++) {
		if(s[i] == 'D') {
			mad = i;
		}
		if(s[i] == 'U' && miu == n) {
			miu = i;
		}
	}
	for(int i=0; i<n; i++) {
		if(s[i] == 'U') {
			ans += n-i-1;
			if(i<mad) {
				ans += i*2;
			}
		}else {
			ans += i;
			if(i>miu) {
				ans += (n-1-i)*2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
