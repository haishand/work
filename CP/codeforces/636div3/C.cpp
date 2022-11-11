#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

int t, n;
ll a[N];
inline int sgn(int x) {
    return x>0?1:-1;
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        int i, j;
        ll ans = 0;
        for(i=1; i<=n; i++) {
            ll cur = a[i];
            j = i;
            while(j<=n && sgn(a[i]) == sgn(a[j])) {
                cur = max(cur, a[j]);
                j++;
            }
            ans += cur;
            i = j-1;
        }
        cout << ans << endl;
    }
    return 0;
}