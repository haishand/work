#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	vector<int> sm(n+1), bg(n+1);
	sm[0] = bg[n] = 0;
	for(int i=1; i<=n; i++) {
		if(s[i-1] == '<') {
			sm[i] = sm[i-1] + 1;	
		}else {
			sm[i] = 0;
		}
	}
	for(int i=n-1; i>=0; i--) {
		if(s[i] == '>') {
			bg[i] = bg[i+1] + 1;
		}else {
			bg[i] = 0;
		}
	}
	
	/*
	for(int i=0; i<=n; i++) {
		printf("sm[%d]=%d, bg[%d]=%d\n", i, sm[i], i, bg[i]);
	}
	*/
	ll ans = 0;
	for(int i=0; i<=n; i++) {
		ans += max(sm[i], bg[i]);
	}
	cout << ans << endl;
	return 0;
}
