#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define MOD  998244353

LL N, M, K;

LL qpow(LL base, LL pow) {
    return pow?((pow&1?base:1)*qpow(base*base%MOD, pow/2))%MOD:1;
}
LL qpow2(LL base, LL pow) {
    LL res = 1;
    while(pow) {
        if(pow&1) {
            res = res*base%MOD;
        }
        base = base*base%MOD;
        pow /= 2;
    }
    return res%MOD;
}

int main() {
    cin >> N >> M >>K;
    LL ans = 0;
    LL temp = 1;
    for(int k=0; k<=K; k++) {
        ans += ((M * temp)%MOD * qpow(M-1, N-1-k))%MOD;
        ans %= MOD;
        temp = (temp * (N-k-1))%MOD * qpow(k+1, MOD-2);
        temp %= MOD;
    }
    cout << ans << endl;
    return 0;
}