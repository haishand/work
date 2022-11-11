#include<iostream>
#include<algorithm>

#define LL  long long
#define MAXN    500010
using namespace std;

int N;

struct number{
    int v, n;
};
number a[MAXN];
LL tree[MAXN];

// rankn[i]=j：第i个数的名次是j
int rankn[MAXN];

LL ANS;

inline int lowbit(int x) {
    return x&(-x);
}

inline void update(int i, int v) {
    for(;i<=N; i+=lowbit(i))
        tree[i] += v;
}

inline LL getsum(int i) {
    LL res = 0;
    for(;i;i-=lowbit(i))
        res += tree[i];
    return res;
}

inline bool cmp(number n1, number n2) {
    if(n1.v == n2.v)
        return n1.n<n2.n;
    return n1.v<n2.v;
}

void debug(int *p, int n ) {
    for(int i=1; i<=n; i++) {
        printf("%d\n", p[i]);
    }
}
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &a[i].v);
        a[i].n = i;
    }
    sort(a+1, a+N+1, cmp);

/*
    // debug
    for(int i=1; i<=N; i++) {
        printf("%d\n", a[i]);
    }
    */
   for(int i=1; i<=N; i++) {
       rankn[a[i].n] = i;
       printf("rankn[%d]=%d\n", a[i].n, i);
   }

//    debug(rankn, N);
    
    ANS = 0;
    for(int i=1; i<=N; i++) {
        update(rankn[i], 1);
        ANS += i-getsum(rankn[i]);
    }
    cout<<ANS<<endl;
   return 0;
}