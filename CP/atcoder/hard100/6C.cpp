#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int ns = s.size(), nt = t.size();
	int pos = -1;
	int found = s.find(t);
	if(found!=string::npos) {
		pos = found;
	}
	for(int i=ns-1; i>=0&&pos==-1; --i) {
		int cnt = 0;
		int k = i;
		int j = nt-1;
		while(cnt<nt && (s[k]=='?' || s[k] == t[j])) {
			--k; --j;
			++cnt;
		}
		if(cnt == nt) {
			pos = k+1;
			break;
		}
	}

	if(pos == -1) {
		cout << "UNRESTORABLE";
	}else {
		for(int i=0; i<ns; ) {
			if(i==pos) {
				cout << t;
				i+=nt;
			}else{
				if(s[i] == '?') {
					cout << 'a';
				}else {
					cout << s[i];
				}
				++i;
			}
		}
	}
    return 0;
}
