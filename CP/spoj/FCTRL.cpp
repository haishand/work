// FCTRL - Factorial
#include <iostream>
using namespace std;
#define LL	long long
LL sum;

int main() {
	int t, N;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &N);
		sum = 0;
		while(N) {
			sum += 1LL*N/5;
			N/=5;
		}
		cout << sum << endl;
	}

	return 0;
}