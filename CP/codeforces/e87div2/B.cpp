#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int inf = 0x3f3f3f3f;
int T;
int main() {
    cin >> T;
    string s;
    while(T--) {
        cin >> s;
        int n = s.length();
        int a, b, c, ans = inf;
        a = b = c = inf;
        for(int i=0; i<n; i++) {
            int d = s[i] - '0';
            if(d==1) {
                a = i;
            }
            if(d==2) {
                b = i;
            }
            if(d==3) {
                c = i;
            }
            ans = min(ans, max({a, b, c})-min({a, b, c}) + 1);
        }
        cout << (ans>n?0:ans) << endl;
    }
    return 0;
}