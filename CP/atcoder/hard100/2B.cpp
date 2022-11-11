#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	stack<char> st;
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
		case '0':
		case '1':
			st.push(s[i]);
			break;
		case 'B':
			st.pop();
			break;
		}
	}
	string ans = "";
	while (!st.empty()) {
		char c = st.top(); st.pop();
		ans.push_back(c);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}

/*
int main() {
	int n;
    ll k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	ll self = 0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i]>a[j]) {
				++self;
			}
		}
	}

	ll ans = 0;
	ans = (ans + self*k)%MOD;

	for(int i=0; i<n; i++) {
		int t = 0;
		for(int j=0; j<n; j++) {
			if(a[j]<a[i]) {
				++t;
			}
		}
		ans += t*(k*(k-1)/2%MOD);
		ans %= MOD;
	}
	cout << ans << endl;
}
*/
