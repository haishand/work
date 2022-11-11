#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	ll ans = 0;
	for(int r=0; r<=N/R; r++) {
		for(int g=0; g<=min(N/G, N-r); g++) {
			int t = N-r*R-g*G;
			if(t>=0 && t%B==0) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
