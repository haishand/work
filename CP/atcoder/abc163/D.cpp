#include <iostream>
using namespace std;
#define LL	long long
const LL MOD=1e9+7;

int N, K;
int main() {
	cin >> N >> K;
	LL ans = 0;
	for(int i=K; i<=N+1; i++) {
		LL left = 1LL * (0+i-1)*i/2;
		LL right = 1LL * (N-i+1+N)*i/2;
		ans += right - left + 1;
		ans %= MOD;
	}
	cout << ans <<endl;
	return 0;
}