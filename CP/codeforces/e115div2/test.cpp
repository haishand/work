#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 4;

int main() {
	int a[N] = {1, 3, 2, 7};
	sort(a, a+N);

	auto it = lower_bound(a+1, a+3, 3);
	cout << *it << endl;
	return 0;
}

