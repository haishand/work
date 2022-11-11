#include<bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXLEN = 20;

int ans = 10;
void solve(int dep, char t[MAXLEN], string& s) {
	if(dep == 10) {
		t[dep] = 0;
		vector<int> score(2);
		vector<int> rest(2);
		rest[0]=rest[1] = 5;
		for(int i=0; i<10; i++) {
			if(t[i] == '1') {
				++score[i%2];
			}
			--rest[i%2];
//			printf("%s, score[0]=%d, score[1]=%d, rest[0]=%d, rest[1]=%d\n", t, score[0], score[1], rest[0], rest[1]);
			if(score[0]>score[1]+rest[1] || score[1]>score[0]+rest[0]) {
				if(ans>i) {
					ans = i+1;
				}
			}

		}
		return;
	}
	if(s[dep] == '?') {
		t[dep] = '1';
		solve(dep+1, t, s);
		t[dep] = '0';
		solve(dep+1, t, s);
	}else {
		t[dep] = s[dep];
		solve(dep+1, t, s);
	}

}
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		
		ans = 10;
		char t[MAXLEN];
		solve(0, t, s);
		cout << ans << endl;
	}
	return 0;
}
