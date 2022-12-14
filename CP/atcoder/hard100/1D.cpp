#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	
	int n = s.size();
	// count the even/odd numbers
	vector<int> count(2, 0);

	// the final answer
	vector<int> ans(n, 0);
	char cur = s[0];
	// the last 'R' index of most inside [RL]
	int last = 0;
	for(int i=0; i<n; i++) {
		if(s[i] == cur) {
			++count[i%2];
		}else {
			if(s[i] == 'L') {
				// s[i-1] must be 'R', this is the most inside 'R'
				last = i-1;
//				printf("last = %d\n", last);
				ans[last] += count[last%2];
				ans[last+1] += count[(last+1)%2];
			}else {
				// s[i-1] must be 'L'
				ans[last] += count[last%2];
				ans[last+1] += count[(last+1)%2];
			}
			count[0] = count[1] = 0;
			++count[i%2];
			cur= s[i];
		}
	}
	ans[last] += count[last%2];
	ans[last+1] += count[(last+1)%2];

	for(int i=0; i<n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
