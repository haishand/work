#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for(int i=0; i<n; i++) {
		int j = i;
		while(j<n && s[j]==s[i]) {
			++j;
		}
		string q = "RGB";
		q.erase(q.find(s[i]), 1);
		if(j<n) q.erase(q.find(s[j]), 1);
		for(int k=i+1; k<j; k+=2) {
			++ans;
			s[k] = q[0];
		}
		i=j-1;
	}
	cout << ans << endl;
	cout << s << endl;
    return 0;
}
