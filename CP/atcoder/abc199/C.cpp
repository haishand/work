#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5+10;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	string pre = s.substr(0, n);
	string post = s.substr(n);

	int q;
	cin >> q;
	for(int i=0; i<q; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		switch(t) {
			case 1:
				if(a-1<n && b-1<n) {
					swap(pre[a-1], pre[b-1]);
				}else if(a-1<n && b-1>=n) {
					swap(pre[a-1], post[b-n-1]);
				}else {
					swap(post[a-n-1], post[b-n-1]);
				}
				break;
			case 2:
				swap(pre, post);
				break;
		}
	}
	cout << pre+post << endl;
	return 0;
}
