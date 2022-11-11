#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

#define LL  long long
#define P   1000000007

using namespace std;
int K;

int gcd1(int m, int n) {
    return n==0?m:gcd1(m%n, n);
}

int gcd2(int m, int n) {
    int t;
    while(n>0) {
        t = m%n;
        m = n;
        n = t;
    }
    return m;
}
int main()
{
    scanf("%d", &K);
    LL sum = 0;
    for(int a = 1; a<=K; a++) {
        for(int b=1; b<=K; b++) {
            int t = gcd2(a, b);
            t %= P;
            for(int c=1; c<=K; c++) {
                int tt = gcd2(t, c);
                sum += tt;
                sum %= P;
            }
        }
    }
    cout << sum << endl;
    return 0;
}