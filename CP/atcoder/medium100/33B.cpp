#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	stack<char> st;
	for(int i=0; i<n; i++) {
		switch(s[i]) {
			case '0':
			case '1':
				st.push(s[i]);
				break;
			case 'B':
				if(!st.empty())
					st.pop();
				break;
		}
	}
	string ans="";
	while(!st.empty()) {
		char c = st.top(); st.pop();
		ans.push_back(c);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
