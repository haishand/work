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
		int n = s.size();
		int na = 0;
		vector<int> ans;
		int flag = 0;
		for(int i=0; i<n; i++) {
			if(s[i] == 'o' && s[i+1]=='n' && s[i+2] == 'e') {
				++na;
				if(flag) {
					--na;
					ans.pop_back();
					flag = 0;
				}
				if(i!=0 && s[i]==s[i-1]) {
					ans.push_back(i+2);
				}else {
					ans.push_back(i+1);
				}
			}else if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
				++na;
				if(i!=0 && s[i]==s[i-1]) {
					ans.push_back(i+2);
				}else {
					ans.push_back(i+1);
				}
				flag = 1;
				++i;
			}else {
				flag = 0;
			}
		}
		cout << na << endl;
		for(int i=0; i<ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		cout << endl;

	}
	return 0;
}
