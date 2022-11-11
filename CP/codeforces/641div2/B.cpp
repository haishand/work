#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;

int t, n;
int s[N];
int dp[N];
int main() {
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> s[i];
        }

        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++) {
            dp[i] = 1;
        }
        /*
        // 超时dp
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i/2; j++) {
               if(i%j==0 && s[i]>s[j]) {
                   dp[i] = max(dp[i], dp[j]+1);
               } 
            }
        }
        */
       for(int i=1; i<=n; i++) {
           for(int j=i*2; j<=n; j+=i) {
               if(s[j]>s[i]) {
                   dp[j] = max(dp[j], dp[i]+1);
               }
           }
       }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
        
    }
    return 0;
}