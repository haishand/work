#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for(;;) {
		if(a == b && b == c) {
			if(a%2 == 0) {
				ans = -1;
			}
			break;
		}
		if(a%2 == 1 || b%2 == 1 || c%2 == 1){
			break;
		}
		++ans;
		int ta = b/2 + c/2;
		int tb = a/2 + c/2;
		int tc = a/2 + b/2;
		a = ta; b = tb; c = tc;
	}
	cout << ans << endl;
	return 0;
}
