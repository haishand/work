#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i=1; i<n; i++) {
		vector<int> flag(26);
		int cnt = 0;
		for(int j=0; j<i; j++) {
			flag[s[j]-'a'] = 1;
		}
		for(int j=i; j<n; j++) {
			int k = s[j] - 'a';
			if(flag[k] == 1) {
				++flag[k];	
				++cnt;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
