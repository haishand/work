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
        int cnt[4] = {};
        int l=0, r = 0;
        int ans = inf;
        // 思考时可以考虑中间情况，不要从头或从尾考虑，中间考虑好了，看看头尾是否满足即可。
        for(r=0; r<n; r++) {
            int d = s[r] - '0';
            cnt[d] ++;
            while(cnt[s[l]-'0']>1) {
                cnt[s[l]-'0']--, ++l;
            }
            if(cnt[1] && cnt[2] && cnt[3]) {
                ans = min(ans, r-l+1);
            }
        }
        if(ans>n) ans = 0;
        cout <<ans<< endl;

    }
    return 0;
}