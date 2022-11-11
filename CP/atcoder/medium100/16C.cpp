#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	int sum = 0;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	if(sum%10==0) {
		int found = 0;
		sort(s.begin(), s.end());
		for(int i=0; i<n; i++) {
			if((sum-s[i])%10 != 0) {
				sum -= s[i];
				found = 1;
				break;
			}
		}
		if(found) {
			cout << sum << endl;
		}else {
			cout << 0 << endl;
		}
	}else {
		cout << sum << endl;
	}
	return 0;
}
