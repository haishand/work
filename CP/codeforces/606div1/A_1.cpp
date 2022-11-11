#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<int> ans;
		for(string t : {"twone", "one", "two"}) {
			for(size_t pos = 0; (pos = s.find(t, pos)) != string::npos;) {
				s[pos+t.length()/2] = '?';
				ans.push_back(pos+t.length()/2);
			}
		}
		cout << ans.size() << endl;
		for(auto e : ans) {
			cout << e+1 << " ";
		}
		cout << endl;
	}
	return 0;
}
