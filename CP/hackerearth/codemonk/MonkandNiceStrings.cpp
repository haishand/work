#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
	cin >> N;
	vector<string> vs(N);
	for(int i=0; i<N; i++) {
		string s;
		cin >> s;
		vs[i] = s;
		int ans = 0;
		for(int j=0; j<i; j++) {
			if(vs[j]<vs[i]) {
				++ans;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
