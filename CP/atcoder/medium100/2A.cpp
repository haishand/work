#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	string S;
	cin >> S;
	ll ans = 0;
	ll b = 0;
	for(int i=0; i<S.size(); i++) {
		if(S[i] == 'B') {
			++b;
		}else {
			ans += b;
		}
	}
	cout << ans << endl;
	return 0;
}
