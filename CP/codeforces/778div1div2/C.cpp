#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, less<ll>>  qa, qb;
		ll sum = 0;
		for(int i=0; i<n; i++) {
			ll a;
			cin >> a;
			qa.push(a);
			sum+=a;
		}

		qb.push(sum);

		while(!qa.empty() && !qb.empty()) {
			ll a = qa.top();
			ll b = qb.top();
//			printf("a=%d, b=%d\n", a, b);
			if(a==b) {
				qa.pop(); qb.pop();
			}else if(a<b) {
				qb.pop();
				qb.push(b/2); qb.push((b+1)/2);
			}else {
				break;
			}
		}

		if(qa.empty() && qb.empty()) {
			cout << "Yes" << endl;
		}else {
			cout << "No" << endl;
		}
	}
	return 0;
}
