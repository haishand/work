#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
using ll = long long;
int nex[MAXN];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
		string a;
		cin >> a;
		
		string ms = a;
		int fb = 0;
		for(int i=1; i<n; i++) {
			if(a[i] == '1' && i>0 && a[i-1] != '1') {
				string ls = a.substr(0, i);
				string rs = a.substr(i, n-i);
				string ns = rs + ls;
				if(ns >  ms) {
					ms = ns;
					fb = i;
				}
			}
		}

		// ms string period
		// next[i] = k: s[1..k] = s[i-k+1, i]
		nex[0] = 0;
		for(int i=1; i<n; i++) {
			int j = nex[i-1];
			while(ms[i] != ms[j] && j>0) {
				j = nex[j-1];
			}
			if(ms[i] == ms[j]) {
				++j;
			}
			nex[i] = j;
		}
		ll period = n - nex[n-1];
		ll ans = fb + (k-1)*period;
		cout << ans << endl;

    }
    
    return 0;
}

