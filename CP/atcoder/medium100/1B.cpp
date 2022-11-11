#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> vis(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	int s = 1;
	int ans = 0;
	int found = 1;
	while(s != 2) {
		s = a[s];
		if(vis[s]) {
			found = 0;
			break;
		}
		vis[s] = 1;
		++ans;
	}
	if(found) {
		cout << ans << endl;
	}else {
		cout << "-1" << endl;
	}
	return 0;
}
