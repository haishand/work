#include<bits/stdc++.h>

using ll = long long;
using namespace std;

const int N = 1e6+10;
ll A, B, C, D;
ll s[N];

int main() {
    cin >> A >> B >>C >>D;
    for(int i=A; i<=B; i++) {
        s[i+B]++;
        s[i+C+1]--;
    }
    for(int i=1; i<N; i++) {
        s[i] += s[i-1];
    }
    for(int i=1; i<N; i++) {
        s[i] += s[i-1];
    }

    ll ans = 0;
    for(int i=C; i<=D; i++) {
        ans += s[N-1] - s[i];
    }
    cout << ans << endl;
    return 0;
}