#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5+10;
int main() {
	int N;
	cin >> N;
	string s, t;
	cin >> s >> t;

	int ans = 2*N;
	for(int i=0; i<N; i++) {
		string ss = s.substr(i, N-i);
		if(t.find(ss) ==0) {
			ans -= ss.length();
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
