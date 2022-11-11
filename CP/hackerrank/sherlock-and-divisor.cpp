#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ret = 1;
    int p, e;
    if(n%2==0) {
        n /= 2;
        p = 2;
        while(p<=n) {
            if(p*p>n) p = n;
            e = 0;
            while(n%p==0) {
                ++e;
                n/=p;
            }
            cout << p << ": " << e+1 << endl;
            ret *= e+1;
            ++p;
        }
    }
    return ret;

}
int main()
{
    int t, n;
    cin>>t;
    while(t--) {
        cin >> n;
        if(n%2) {
            cout << 0 << endl;
           continue;
        }
        int cnt = 0;
        int i;
        for(i=1; i*i<n; i++) {
            if(n%i==0) {
                if(i%2==0) ++cnt;
                if((n/i)%2==0) ++cnt;
            }
        }
        if(i*i==n&&i%2==0) ++cnt;
        //cout << cnt << endl;
        cout << solve(n) << endl;
    }
    return 0;
}

