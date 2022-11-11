#include<bits/stdc++.h>
using namespace std;

using ll = long long;

char color[3] = {'R', 'G', 'B'};

char select_diff(char a, char b) {
	for(int i=0; i<3; i++) {
		if(color[i]!=a && color[i]!=b) {
			return color[i];
		}
	}
	assert(0);
	return -1;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char pre = s[0];
	int same_cnt = 1;
	int ans = 0;
	for(int i=1; i<=n; i++) {
//		printf("pre:%c, current:%c\n", pre, s[i]);
		if(pre!=s[i] || (i==n)) {
			ans += same_cnt/2;
			for(int j=i-same_cnt+1;j<i; j+=2) {
				s[j] = select_diff(s[j-1], s[j+1]);
			}
//			printf("before %d: same_cnt=%d\n", i, same_cnt);
			pre = s[i];
			same_cnt = 1;
		}else {
			++same_cnt;
		}
	}
	/*
	if(same_cnt) {
		for(int j=n-same_cnt+1;j<n; j+=2) {
			s[j] = select_diff(s[j-1], s[j+1]);
		}
	}
	*/
	ans += same_cnt/2;
	cout << ans << endl;

	cout << s << endl;
    return 0;
}
