#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bsearch_x(int low, int high, int y) {
	if(low<=high) {
		int mid = (low+high)/2;
		cout<<"? " << mid << " " << y << endl;
//		printf("? %d %d\n", mid, y);
		string ans;
		cin >> ans;
		if(ans == "YES") {
			return bsearch_x(mid+1, high, y);
		}else {
			return bsearch_x(low, mid-1, y);
		}
	}
	return low-1;
}

int bsearch_y(int low, int high, int x) {
	if(low<=high) {
		int mid = (low+high)/2;
		cout<<"? " << x << " " << mid << endl;
//		printf("? %d %d\n", x, mid);
		string ans;
		cin >> ans;
		if(ans == "YES") {
			return bsearch_y(mid+1, high, x);
		}else {
			return bsearch_y(low, mid-1, x);
		}
	}
	return low-1;
}

int main() {
	int a, b, c;
	a = bsearch_x(0, 1000, 0);
	b = bsearch_x(0, 1000, 2*a);
	c = bsearch_y(0, 1000, 0);
	
	printf("a=%d, b=%d, c=%d\n", a, b, c);
	int area = 2*a*2*a + b*(c-2*a);
	cout << "! " << area << endl;
	return 0;
}

