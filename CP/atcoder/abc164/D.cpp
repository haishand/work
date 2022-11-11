#include<iostream>
#include<cmath>

#define LL  long long
using namespace std;
const int MAXN = 2e5+10;

LL T[MAXN];
int mod[2019];
LL ans = 0;

inline LL count(int n) {
    return 1LL*n*(n-1)/2;
}
int main() {
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int n = S.length();

    T[n] = 0;
    int pre = 1;
    mod[0] = 1;
    for(int i=n-1; i>=0; i--) {
    	pre *= 10;
        T[i] = T[i+1]+pre*(S[i]-'0');
        T[i] %= 2019;
        mod[T[i]]++;
        pre %= 2019;
    } 

    ans  = 0;
    for(int i=0; i<2019; i++) {
    	if(mod[i])
        	ans += count(mod[i]);
    }
    cout << ans << endl;
    return 0;
}