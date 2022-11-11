#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;

	vector<int> t(n+1), x(n+1), y(n+1);
	t[0] = 0; x[0]=0; y[0]=0;
	for(int i=1; i<=n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}

	int flag = 1;
	for(int i=1; i<=n; i++) {
		int tt = t[i] - t[i-1];
		int dd = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
		if((dd>tt) || (dd%2 != tt%2)) {
//			printf("tt = %d, dd = %d\n", tt, dd);
			flag = 0;
			break;
		}
	}
	if(flag == 0) {
		cout << "No" << endl;
	}else {
		cout << "Yes" << endl;
	}
    return 0;
}
